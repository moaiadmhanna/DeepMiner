//
// Created by Muayad Mhanna on 03.04.24.
//

#include "MinerBotsFabrik.h"

MinerBotsFabrik::MinerBotsFabrik() {
    this->MinerBotPrototype[0] = new Miner("CoordinateSort");
    this->MinerBotPrototype[1] = new Miner("ValueExtraction");
    this->MinerBotPrototype[2] = new Miner("MedianFinder");
}

void MinerBotsFabrik::minningBotsPrinter() const {
    for(int i  = 0; i < NUMBER_OF_BOTS; i++){
        cout << i + 1 << "- ";
        getAbilityInfo(this->MinerBotPrototype[i]->ability);
        cout << endl;
    }
}

Miner *MinerBotsFabrik::getMiner(int index) {
    return MinerBotPrototype[index]->clone();
}
