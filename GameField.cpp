//
// Created by Muayad Mhanna on 03.04.24.
//

#include "GameField.h"

GameField::GameField() {
    for(int x = 0; x < X_AND_Y_SIZE; x++) {
        vector<vector<int>> tempVec1;
        for(int y = 0; y < X_AND_Y_SIZE; y++) {
            vector<int> tempVec2;
            for(int z = 0; z < Z_SIZE; z++) {
                int randomNumber = 1 + rand() % 9;
                tempVec2.push_back(randomNumber);
            }
            tempVec1.push_back(tempVec2);
        }
        gameField.push_back(tempVec1);
    }
}

void GameField::gameFieldPrinter(Miner* miner) {
    for(int i = 0; i < X_AND_Y_SIZE; i++){
        closeRow();
        cout << " ";
    }
    cout << endl;
    for(int x = 0; x < X_AND_Y_SIZE; x++) {
        for (int y = 0; y < X_AND_Y_SIZE; y++) {
            if(miner->coordinate->x == x && miner->coordinate->y == y){
                cout <<"|  M   | ";
                continue;
            }
            firstRow(gameField[x][y][0]);
        }
        cout << endl;
        for(int i = 0; i < X_AND_Y_SIZE; i++){
            int layer = gameField[x][i].size() - 1 ;
            secondRow(layer);
        }
        cout << endl;
        for(int a = 0 ; a < X_AND_Y_SIZE; a++){
            closeRow();
            cout << " ";
        }
        cout << endl;
    }
}
