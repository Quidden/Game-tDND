#pragma once
#include <string>
#include <iostream>
#include "Person.h"

bool ErrorOutput(std::string error);
void SetTextColor(int color);
void TextToConfirmTheSelection();
void HeroInfoSelecting(PlayerC* temp, int& Subverification);
PlayerC* SelectingGameCharacter();
void TheEnemyMove(PlayerC& Player, EnemyC& Enemy);
void ThePlayerMove(PlayerC& Player, EnemyC& Enemy);
void Battle(PlayerC& Player);
void Inventory(PlayerC& Player);
void InventoryRealization(PlayerC& Player);
