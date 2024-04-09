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

void GameField::gameFieldPrinter(Miner* miner, int playerNumber) {
    for(int i = 0; i < X_AND_Y_SIZE; i++){
        closeRow();
        cout << " ";
    }
    cout << endl;
    for(int x = 0; x < X_AND_Y_SIZE; x++) {
        for (int y = 0; y < X_AND_Y_SIZE; y++) {
            if(miner->x == x && miner->y == y){
                cout <<"|  P"<<playerNumber<<"  | ";
                continue;
            }
            if(gameField[x][y].size() == 0){
                cout <<"|  *   | ";
                continue;
            }
            firstRow(gameField[x][y][0]);
        }
        cout << endl;
        for(int i = 0; i < X_AND_Y_SIZE; i++){
            int layer = gameField[x][i].size() - 1 ;
            if(gameField[x][i].size() == 0){
                secondRow(0);
                continue;
            }
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

void GameField::gameFieldReload() {
    for(int x = 0; x < X_AND_Y_SIZE; x++){
        for(int y = 0; y < X_AND_Y_SIZE; y++){
            for(int i = 0; i < 10 - gameField[x][y].size(); i++){
                int randomNumber = 1 + rand() % 9;
                gameField[x][y].push_back(randomNumber);
            }
            int randomnNumber = 1 + rand() % 3;
            auto randomDevice = std::random_device {};
            auto randomEngine = std::default_random_engine { randomDevice() };
            switch (randomnNumber){
                case 1:
                    shuffle(gameField[x][y].begin(),gameField[x][y].end(), randomEngine);
                    break;
                case 2:
                    sort(gameField[x][y].begin(),gameField[x][y].end(),greater<int>());
                    break;
                case 3:
                    sort(gameField[x][y].begin(),gameField[x][y].end());
                    break;

            }
        }
    }
}
