#ifndef APPROACH_HANDLER_HPP
# define APPROACH_HANDLER_HPP
#include "AuthenticationTicketMessage.hpp"
#include "WorldClient.hpp"
#include "World.hpp"
#include "IPC.hpp"
#include "IpcTicketAccountMessage.hpp"
#include "AuthenticationTicketAcceptedMessage.hpp"
#include "ServerSettingsMessage.hpp"
#include "ServerOptionalFeaturesMessage.hpp"
#include "AccountCapabilitiesMessage.hpp"
#include "TrustStatusMessage.hpp"
#include "Breeds.hpp"
#include "CharacterBaseInformations.hpp"
#include "CharactersListMessage.hpp"
#include "ReloginTokenStatusMessage.hpp"
#include "CharacterNameSuggestionSuccessMessage.hpp"
#include "CharacterCreationResultMessage.hpp"
#include "CharacterCreationRequestMessage.hpp"
#include "CharacterCreationResultEnum.hpp"
#include "CharacterDeletionRequestMessage.hpp"
#include "CharacterDeletionErrorMessage.hpp"
#include "CharacterDeletionErrorEnum.hpp"
#include "CharacterSelectionMessage.hpp"
#include "CharacterSelectedSuccessMessage.hpp"
#include "NotificationListMessage.hpp"
#include "CharacterSelectedErrorMessage.hpp"
#include "CharacterLoadingCompleteMessage.hpp"

#include "Character.hpp"
#include "CharactersManager.hpp"

class ApproachHandler
{
public:
	static void AuthenticationTicketMessageHandler(BinaryReader &reader, WorldClient &client);
	static void CharactersListRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void ReloginTokenRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void CharacterNameSuggestionRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void CharacterCreationRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void CharacterDeletionRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void CharacterSelectionMessageHandler(BinaryReader &reader, WorldClient &client);

	static ByteArray getOptionalFeatures();
	static int getBreedsNumber();
	static ByteArray getBreeds();
	static bool isBreedAllowed(int id);
	static bool isValidName(std::string name);
	static void sendCharactersList(WorldClient &client);
};


#endif