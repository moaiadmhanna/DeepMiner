//
// Created by Muayad Mhanna on 03.04.24.
//

#ifndef DEEPMINER_MINER_H
#define DEEPMINER_MINER_H

#include "../Defaults/defaults.h"

class Miner {
    public:
        Miner(std::string ability);
        std::string ability;
        int x;
        int y;
        char type;
        int score;
        Miner* clone() const;
};


#endif //DEEPMINER_MINER_H
