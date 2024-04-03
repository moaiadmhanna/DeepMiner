//
// Created by Muayad Mhanna on 03.04.24.
//

#ifndef DEEPMINER_MINERBOTSFABRIK_H
#define DEEPMINER_MINERBOTSFABRIK_H
#include "Miner.h"
#include "../Defaults/defaults.h"

class MinerBotsFabrik {
    public:
        MinerBotsFabrik();
        ~MinerBotsFabrik();
        Miner* MinerBotPrototype[NUMBER_OF_BOTS];
};


#endif //DEEPMINER_MINERBOTSFABRIK_H
