//
// Created by Muayad Mhanna on 03.04.24.
//

#include "MinerBotsFabrik.h"

MinerBotsFabrik::MinerBotsFabrik() {
    this->MinerBotPrototype[0] = new Miner("Coordinate Sort");
    this->MinerBotPrototype[1] = new Miner("Value Extraction");
}
