//
// Created by Muayad Mhanna on 03.04.24.
//

#include "Miner.h"

Miner::Miner(std::string ability) {
    this->ability = ability;
    this->score = 0;
    this->x = 0;
    this->y = 0;
}

Miner* Miner::clone() const{
    return new Miner(*this);
}
