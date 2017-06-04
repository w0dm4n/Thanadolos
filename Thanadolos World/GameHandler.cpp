#include "Globals.h"
#include "GameHandler.hpp"

void GameHandler::GameContextCreateRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	if (client.character == NULL)
	{
		Logger::Error("An error occured on game context, can't get client character.");
		client.disconnect();
		return;
	}

	
	client.sendMessage(GameContextDestroyMessage());
	client.sendMessage(GameContextCreateMessage(1));

	// emotes
	
	//client.sendMessage(UpdateLifePointsMessage(42, 42));
	client.getWorld()->teleportClient(client.character->getCharacterRecord().get("MapId"), client.character->getCharacterRecord().get("CellId"), client);

	if (client.character->isFirstContext())
		client.character->onConnected();
}


void GameHandler::MapComplementaryInformationsDataMessageHandler(BinaryReader &reader, WorldClient &client)
{
	if (client.character->getMap() != NULL)
		client.sendMessage(client.character->getMap()->getMapComplementaryInformationsDataMessage());
}

void GameHandler::GameMapMovementRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	GameMapMovementRequestMessage message;
	message.deserialize(reader);

	// check direction line if cell mov
	int i = 0;
	int cellId = 0;
	int directionId = 0;
	while (i < message.keyMovements.size())
	{
		cellId = message.keyMovements[i] & 4095;
		directionId = message.keyMovements[i] >> 12 & 7;
		i++;
	}
	client.character->updatePosition(client.character->getMap()->getMapRecord().get("id"), cellId);
	client.character->updateDirection(directionId);
	client.character->getMap()->sendMap(GameMapMovementMessage(message.keyMovements, directionId, client.character->getCharacterRecord().get("Id")));
}

void GameHandler::ChangeMapMessageHandler(BinaryReader &reader, WorldClient &client)
{
	ChangeMapMessage message;
	message.deserialize(reader);

	Map *map = client.getWorld()->getMapInstance(message.mapId);
	if (map->getMapRecord().pointer() != NULL)
	{
		int cellId = client.character->getCharacterRecord().get("CellId");
		int mapDirection = -1;

		if (message.mapId == (int)client.character->getMap()->getMapRecord().get("topNeighbourId"))
		{
			cellId += 532;
			mapDirection = 1;
			client.character->updateDirection(DirectionsEnum::DIRECTION_NORTH);
		}
		else if (message.mapId == (int)client.character->getMap()->getMapRecord().get("rightNeighbourId"))
		{
			cellId -= 13;
			mapDirection = 2;

			client.character->updateDirection(DirectionsEnum::DIRECTION_EAST);
		}
		else if (message.mapId == (int)client.character->getMap()->getMapRecord().get("bottomNeighbourId"))
		{
			cellId -= 532;
			mapDirection = 3;

			client.character->updateDirection(DirectionsEnum::DIRECTION_SOUTH);
		}
		else if (message.mapId == (int)client.character->getMap()->getMapRecord().get("leftNeighbourId"))
		{
			cellId += 13;
			mapDirection = 4;

			client.character->updateDirection(DirectionsEnum::DIRECTION_WEST);
		}

		// map scroll action with mapDirection
		if (cellId > 0 && cellId < 600)
			client.getWorld()->teleportClient(map->getMapRecord().get("id"), cellId, client);
	}
}

void GameHandler::StatsUpgradeRequestMessageHandler(BinaryReader & reader, WorldClient & client)
{
	StatsUpgradeRequestMessage message;
	message.deserialize(reader);

	int cost = CharactersManager::getStatsCost(message.statId, client);
	if (cost == -1)
	{
		client.sendMessage(StatsUpgradeResultMessage(StatsUpgradeResultEnum::NONE, 0));
		return;
	}
	int boostPoint = message.boostPoint;
	while (boostPoint > 0)
	{
		cost = CharactersManager::getStatsCost(message.statId, client);
		if ((int)client.character->getStats().getStatsRecord().get("StatsPoints") >= cost)
		{
			client.character->getStats().increaseBaseStats(message.statId);
			client.character->getStats().decreaseStatsPoints(cost);
		}
		boostPoint -= cost;
	}
	client.character->sendStats();
	if (client.character->getStats().getCurrentLife() < client.character->getStats().getMaxLife())
	{
		client.character->stopRegenLife(true);
		client.character->startRegenLife(true);
	}
}

void GameHandler::sendWelcomeMessage(WorldClient &client)
{
	std::vector<std::string> params;
	client.character->replyLangsMessage(1, 89, params);
	
	std::string content = "<font color=\"#EEAD0E\"><b>";
	content += client.getWorld()->getConfig()->getData("WELCOME_MESSAGE");
	content += "</b></font>";
	params.push_back(content);
	client.sendMessage(TextInformationMessage(0, 0, params));
}

void GameHandler::SpellModifyRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	SpellModifyRequestMessage message;
	message.deserialize(reader);

	
	if (client.character->hasSpellId(message.spellId) && (message.spellLevel <= 6 && message.spellLevel >= 1))
	{
		Spell *spell = client.character->getSpellById(message.spellId);
		if (spell != NULL)
		{
			int cost = 0;
			int gain = 0;
			int grade = spell->spellLevel.levelRecord.get("grade");
			if (grade < message.spellLevel)
			{
				for (int i = grade; i < message.spellLevel; i++)
					cost += i;
			}
			else
			{
				int i = (grade - 1);
				while (i > 0)
				{
					gain += i;
					if (i == message.spellLevel)
						break;
					i--;
				}
			}
			if (cost > 0)
			{
				if (client.character->getStats().getSpellsPoints() >= cost)
				{
					if (spell->updateSpellLevel(message.spellLevel))
					{
						client.character->getStats().decreaseSpellsPoints(cost);
						client.sendMessage(SpellModifySuccessMessage(message.spellId, message.spellLevel));
						client.character->sendStats();
					}
					else
						client.sendMessage(SpellModifyFailureMessage());
				}
				else
					client.sendMessage(SpellModifyFailureMessage());
			}
			else if (gain > 0)
			{
				if (spell->updateSpellLevel(message.spellLevel))
				{
					client.character->getStats().increaseSpellsPoints(gain);
					client.sendMessage(SpellModifySuccessMessage(message.spellId, message.spellLevel));
					client.character->sendStats();
				}
				else
					client.sendMessage(SpellModifyFailureMessage());
			}
		}
		else
			client.sendMessage(SpellModifyFailureMessage());
	}
}

void GameHandler::ShortcutBarAddRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	ShortcutBarAddRequestMessage message;
	message.deserialize(reader);
	
	switch (message.barType)
	{
		case ShortcutBarEnum::SPELL_SHORTCUT_BAR:
			client.character->addShortcut(dynamic_cast<ShortcutSpell*>(message.shortcut));
		break;

		case ShortcutBarEnum::GENERAL_SHORTCUT_BAR:
			client.character->addShortcut(dynamic_cast<ShortcutObjectItem*>(message.shortcut));
		break;
	}
}

void GameHandler::ShortcutBarRemoveRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	ShortcutBarRemoveRequestMessage message;
	message.deserialize(reader);
	if (client.character->getShortcut(message.slot, message.barType).pointer() != NULL)
		client.character->removeShortcut(message.slot, message.barType);
}

void GameHandler::ShortcutBarSwapRequestMessageHandler(BinaryReader &reader, WorldClient &client)
{
	ShortcutBarSwapRequestMessage message;
	message.deserialize(reader);

	client.character->swapShortcuts(message.barType, message.firstSlot, message.secondSlot);
}
