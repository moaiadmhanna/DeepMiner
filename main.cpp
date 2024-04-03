#include <iostream>
#include <ctime>
#include "GameField.h"
#include "Bots/MinerBotsFabrik.h"
#include "Bots/Miner.h"
#include "Defaults/defaults.h"
void playerMove(Miner* miner, GameField* gameField){
    char input;
    while(true){
        int xTemp = miner->coordinate->x;
        int yTemp = miner->coordinate->y;
        input = moveChecker();
        switch (input){
            case 'w':
                xTemp--;
                break;
            case 's':
                xTemp++;
                break;
            case 'a':
                yTemp--;
                break;
            case 'd':
                yTemp++;
                break;
        }
        if(xTemp >= 0 && yTemp >= 0 && xTemp < X_AND_Y_SIZE && yTemp < X_AND_Y_SIZE && gameField->gameField[xTemp][yTemp].size() > 0){
            miner->coordinate->x = xTemp;
            miner->coordinate->y = yTemp;
            break;
        }
        cout << "Invalid Move" << endl;
    }
}
int main() {
    srand(time(0));
    GameField* gameField = new GameField();
    MinerBotsFabrik* minningBots = new MinerBotsFabrik();
    Miner* minningBot = minningBots->MinerBotPrototype[0];
    while(true){
        playerMove(minningBot,gameField);
        int x = minningBot->coordinate->x;
        int y = minningBot->coordinate->y;
        gameField->gameField[x][y].erase(gameField->gameField[x][y].begin());
        gameField->gameFieldPrinter(minningBot);
    }
    gameField->gameFieldPrinter(minningBot);
    return 0;
}
