#include "Globals.h"
#include "ApproachHandler.hpp"

ByteArray ApproachHandler::getOptionalFeatures()
{
	ByteArray features;
	return features;
}

ByteArray ApproachHandler::getBreeds()
{
	ByteArray breeds;

	breeds.push_back(Breeds::Feca);
	breeds.push_back(Breeds::Osamodas);
	breeds.push_back(Breeds::Enutrof);
	breeds.push_back(Breeds::Sram);
	breeds.push_back(Breeds::Xelor);
	breeds.push_back(Breeds::Ecaflip);
	breeds.push_back(Breeds::Iop);
	breeds.push_back(Breeds::Cra);
	breeds.push_back(Breeds::Sadida);
	breeds.push_back(Breeds::Sacrieur);
	breeds.push_back(Breeds::Pandawa);
	breeds.push_back(Breeds::Roublard);
	breeds.push_back(Breeds::Zobal);
	breeds.push_back(Breeds::Steamer);
	breeds.push_back(Breeds::Eliotrope);
	breeds.push_back(Breeds::Huppermage);
	breeds.push_back(Breeds::Ouginak);
	return (breeds);
}

bool ApproachHandler::isBreedAllowed(int breed)
{
	ByteArray breeds = ApproachHandler::getBreeds();
	int i = 0;
	while (i < breeds.size())
	{
		if (breeds[i] == breed)
			return true;
		i++;
	}
	return false;
}

int ApproachHandler::getBreedsNumber()
{
	ByteArray breeds = ApproachHandler::getBreeds();
	
	int datas = 0;
	int i = 0;
	while (i < breeds.size())
		datas += pow(2, (breeds[i++] - 1));
	return datas;
}

void ApproachHandler::AuthenticationTicketMessageHandler(BinaryReader &reader, WorldClient &client)
{
	AuthenticationTicketMessage message;
	message.deserialize(reader);

	IpcTicketAccountMessage ticketAccount = client.getWorld()->getIPC()->getTicketsAccountsByTicket(message.ticket);
	if (!ticketAccount.account.empty())
	{
		camp::UserObject account = client.getWorld()->getDatabase()->buildAccount(ticketAccount);
		WorldClient *connected = client.getWorld()->getWorldClientByAccountId(account.get("id"));
		if (connected != NULL)
		{
			connected->disconnect();
			Sleep(1000); // in case the save is long to avoid exploit
		}
		client.setAccount(account);
		client.getWorld()->getDatabase()->loadCharacters(client);
		client.sendMessage(AuthenticationTicketAcceptedMessage());
		client.sendMessage(ServerSettingsMessage("fr", 0, -1, 30));
		client.sendMessage(ServerOptionalFeaturesMessage(ApproachHandler::getOptionalFeatures()));
		client.sendMessage(AccountCapabilitiesMessage(client.getAccount().get("id"), true, ApproachHandler::getBreedsNumber(), ApproachHandler::getBreedsNumber(), 0, true));
		client.sendMessage(TrustStatusMessage(true, true));
	}
	else
	{
		Logger::Error("One client disconnected (can't find account linked to client ticket)");
		client.disconnect();
	}
}

bool ApproachHandler::isValidName(std::string name)
{
	if (!isupper(name.c_str()[0]) || name.length() <= 3)
		return false;
	int i = 0;
	int count_dash = 0;
	while (name[i])
	{
		if (name[i] == '-')
		{
			if (count_dash == 0)
				count_dash++;
			else
				return false;
		}
		int ascii = name.c_str()[i];
		if ((ascii >= 97 && ascii <= 122) || (ascii >= 65 && ascii <= 90) || name[i] == '-')
		{
			if (i > 0 && (ascii >= 65 && ascii <= 90) && name[(i - 1)] != '-')
				return false;
		}
		else
			return false;
		i++;
	}
	return true;
}

void ApproachHandler::sendCharactersList(WorldClient &client)
{
	std::vector<camp::UserObject> records = client.getCharacters();
	std::vector<CharacterBaseInformations> characters;
	int i = 0;
	while (i < records.size())
	{
		Character current(records[i], client.getAccount(), client, false);
		characters.push_back(current.getCharacterBaseInformations());
		i++;
	}
	client.sendMessage(CharactersListMessage(characters, false));
}

void ApproachHandler::CharactersListRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	ApproachHandler::sendCharactersList(client);
}

void ApproachHandler::ReloginTokenRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	if (client.getAccount().pointer() != NULL)
	{
		client.sendMessage(ReloginTokenStatusMessage(true, ""));
	}
	else
	{
		client.sendMessage(ReloginTokenStatusMessage(false, ""));
	}
}

void ApproachHandler::CharacterNameSuggestionRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	std::string suggestion = CharactersManager::generateName();
	if (!suggestion.empty())
		client.sendMessage(CharacterNameSuggestionSuccessMessage(suggestion));
	else
	{
		Logger::Error("An error occurred while trying to generate a character name");
		client.disconnect();
	}
}

void ApproachHandler::CharacterCreationRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	CharacterCreationRequestMessage message;
	message.deserialize(reader);

	int i = 0;
	if (!ApproachHandler::isValidName(message.name))
	{
		client.sendMessage(CharacterCreationResultMessage(CharacterCreationResultEnum::ERR_INVALID_NAME));
		return;
	}

	if (!client.getWorld()->getDatabase()->characterNameAvailable(message.name.c_str()))
	{
		client.sendMessage(CharacterCreationResultMessage(CharacterCreationResultEnum::ERR_NAME_ALREADY_EXISTS));
		return;
	}
	if (client.getCharacters().size() >= std::stoi(client.getWorld()->getConfig()->getData("MAX_CHARACTERS_PER_ACCOUNT")))
	{
		client.sendMessage(CharacterCreationResultMessage(CharacterCreationResultEnum::ERR_TOO_MANY_CHARACTERS));
		return;
	}
	if (!ApproachHandler::isBreedAllowed(message.breed))
	{
		client.sendMessage(CharacterCreationResultMessage(CharacterCreationResultEnum::ERR_NOT_ALLOWED));
		return;
	}

	if (!client.getWorld()->getIPC()->isSynchronized()) // if auth server is down, cant create a character
	{
		Logger::Error("Can't create a new character cause the auth server is not synchronized");
		client.sendMessage(CharacterCreationResultMessage(CharacterCreationResultEnum::ERR_NO_REASON));
		return;
	}

	if (client.getWorld()->getDatabase()->createCharacter(message, client))
	{
		client.sendMessage(CharacterCreationResultMessage(CharacterCreationResultEnum::OK));
		std::vector<camp::UserObject> characters = client.getCharacters();
		client.buildCharacter(characters[(characters.size() - 1)].get("Id"));
		if (client.character != NULL)
		{
			client.sendMessage(NotificationListMessage());
			client.sendMessage(CharacterSelectedSuccessMessage(client.character->getCharacterBaseInformations(), false));
			client.sendMessage(CharacterLoadingCompleteMessage());
		}
		else
		{
			Logger::Error("An error occured while a client was trying to select a character");
			client.sendMessage(CharacterSelectedErrorMessage());
		}
	}
	else {
		client.sendMessage(CharacterCreationResultMessage(CharacterCreationResultEnum::ERR_NO_REASON));
	}
}

void ApproachHandler::CharacterDeletionRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	CharacterDeletionRequestMessage message;
	message.deserialize(reader);

	Sleep(1000); //  due to dofus client
	if (CharactersManager::isMyCharacter(message.characterId, client))
	{
		if (!client.getWorld()->getIPC()->isSynchronized())
		{
			Logger::Error("Can't delete a character cause the auth server is not synchronized");
			client.sendMessage(CharacterDeletionErrorMessage(CharacterDeletionErrorEnum::DEL_ERR_NO_REASON));
			return;
		}
		if (!CharactersManager::removeCharacter(message.characterId, client))
			client.sendMessage(CharacterDeletionErrorMessage(CharacterDeletionErrorEnum::DEL_ERR_NO_REASON));
	}
	else
	{
		client.sendMessage(CharacterDeletionErrorMessage(CharacterDeletionErrorEnum::DEL_ERR_NO_REASON));
	}
}

void ApproachHandler::CharacterSelectionMessageHandler(BinaryReader &reader, WorldClient &client)
{
	CharacterSelectionMessage message;
	message.deserialize(reader);

	if (CharactersManager::isMyCharacter(message.characterId, client))
	{
		client.buildCharacter(message.characterId);
		if (client.character != NULL)
		{
			client.sendMessage(NotificationListMessage());
			client.sendMessage(CharacterSelectedSuccessMessage(client.character->getCharacterBaseInformations(), false));
			client.sendMessage(CharacterLoadingCompleteMessage());
		}
		else
		{
			Logger::Error("An error occured while a client was trying to select a character");
			client.sendMessage(CharacterSelectedErrorMessage());
		}
	}
	else
	{
		Logger::Error("An error occured while a client was trying to select a character");
		client.sendMessage(CharacterSelectedErrorMessage());
	}
}
