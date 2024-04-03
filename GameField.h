//
// Created by Muayad Mhanna on 03.04.24.
//

#ifndef DEEPMINER_GAMEFIELD_H
#define DEEPMINER_GAMEFIELD_H
#include <iostream>
#include <vector>
#include "Defaults/defaults.h"
#include "Bots/Miner.h"

using namespace  std;
class GameField {
    public:
    GameField();
    void gameFieldPrinter(Miner* miner);
    //  x     y      z
    vector<vector<vector<int>>> gameField;

};


#endif //DEEPMINER_GAMEFIELD_H
