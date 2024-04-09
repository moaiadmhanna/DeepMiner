#include <iostream>
#include <ctime>
#include <unistd.h>
#include "GameField.h"
#include "Bots/MinerBotsFabrik.h"
#include "Bots/Miner.h"
#include "Defaults/defaults.h"

Miner* minningPlayerChoose(MinerBotsFabrik* minningbots){
    minningbots->minningBotsPrinter();
    int input;
    while(true){
        cout << "Choose which Minning Bot you want: ";
        cin >> input;
        if(input > 0 && input <= NUMBER_OF_BOTS){break;}
    }
    return minningbots->getMiner(input-1);
}
Miner* minningComputerChoose(MinerBotsFabrik* minningbots){
    minningbots->minningBotsPrinter();
    int randomNumber = rand()% NUMBER_OF_BOTS;
    cout << "Computer chose Bot number " << randomNumber + 1 << endl;
    sleep(2);
    return minningbots->getMiner(randomNumber);
}
void minnersChooser(Miner* miners[], MinerBotsFabrik* minningbots){
    for(int i = 0; i < NUMBER_OF_MINNING_BOTS ; i++){
        int input;
        while(true){
            cout << "Player" << i+1 <<" PLayer[1] or Computer[2]: ";
            cin >> input;
            if(input > 0 && input < 3){break;}
        }
        switch (input){
            case 1:
                miners[i] = minningPlayerChoose(minningbots);
                miners[i]->type = 'p'; // für player
                break;
            case 2:
                miners[i] = minningComputerChoose(minningbots);
                miners[i]->type = 'b'; // für Bot
                break;
        }
    }
}
void playerMove(Miner* miner, GameField* gameField){
    char input;
    while(true){
        int xTemp = miner->x;
        int yTemp = miner->y;
        if(miner->type == 'p') {
            input = moveChecker();
            switch (input) {
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
        }
        else{
            int randomNumber = 1 + rand()%4;
            switch (randomNumber) {
                case 1:
                    xTemp--;
                    break;
                case 2:
                    xTemp++;
                    break;
                case 3:
                    yTemp--;
                    break;
                case 4:
                    yTemp++;
                    break;
            }
        }
        if(xTemp >= 0 && yTemp >= 0 && xTemp < X_AND_Y_SIZE && yTemp < X_AND_Y_SIZE && gameField->gameField[xTemp][yTemp].size() > 0)
        {
            miner->x = xTemp;
            miner->y = yTemp;
            break;
        }
        cout << "Invalid Move" << endl;
    }
}
void coordinateSortAbiltiy(Miner* miner, GameField* gameField){
    int x = miner->x;
    int y = miner->y;
    sort(gameField->gameField[x][y].begin(),gameField->gameField[x][y].end(),greater<int>());
    miner->score += gameField->gameField[x][y][0];
    gameField->gameField[x][y].erase(gameField->gameField[x][y].begin());
}
void valueExtractionAbility(Miner* miner, GameField* gameField){
    int x = miner->x;
    int y = miner->y;
    miner->score += gameField->gameField[x][y][0];
    gameField->gameField[x][y].erase(gameField->gameField[x][y].begin());
    miner->score += gameField->gameField[x][y][0];
    gameField->gameField[x][y].erase(gameField->gameField[x][y].begin());
}
void MedianFinderAbility(Miner* miner, GameField* gameField){
    int x = miner->x;
    int y = miner->y;
    int cnt = 0;
    cnt += gameField->gameField[x][y][0];
    gameField->gameField[x][y].erase(gameField->gameField[x][y].begin());
    cnt += gameField->gameField[x][y][0];
    gameField->gameField[x][y].erase(gameField->gameField[x][y].begin());
    cnt += gameField->gameField[x][y][0];
    gameField->gameField[x][y].erase(gameField->gameField[x][y].begin());
    miner->score = cnt / 3;
}
void positionAndScorePrinter(GameField* gameField, Miner* miners[]){
    for(int i = 0; i < NUMBER_OF_MINNING_BOTS; i++){
        int x = miners[i]->x;
        int y = miners[i]->y;
        cout << "Player " << i+1;
        cout << " xPosition: " << miners[i]->x;
        cout << " yPosition: " << miners[i]->y;
        cout << " Block Value: " << gameField->gameField[x][y][0];
        cout << " Score: " << miners[i]->score;
        cout << endl;
    }
}
int moveOrMine(Miner* miner){
    if(miner->type == 'p') {
        while (true) {
            cout << "Do u want to move[1] or mine[2]: ";
            int input;
            cin >> input;
            if (input > 0 && input < 3) { return input; }
        }
    }
    return 1+ rand()%2;
}
void abilityUse(Miner* miner, GameField* gameField){
    if(miner->ability == "CoordinateSort"){
        if(gameField->gameField[miner->x][miner->y].size() < 1){
            cout << "Cannot mine" << endl;
            sleep(2);
            return;
        }
        coordinateSortAbiltiy(miner,gameField);
        cout << "Player uses CoordinateSort" << endl;
        sleep(2);
    }
    else if(miner->ability == "ValueExtraction"){
        if(gameField->gameField[miner->x][miner->y].size() < 2){
            cout << "Cannot mine" << endl;
            sleep(2);
            return;
        }
        valueExtractionAbility(miner,gameField);
        cout << "Player uses ValueExtraction" << endl;
        sleep(2);
    }
    else if(miner->ability == "MedianFinder"){
        if(gameField->gameField[miner->x][miner->y].size() < 3){
            cout << "Cannot mine" << endl;
            sleep(2);
            return;
        }
        MedianFinderAbility(miner,gameField);
        cout << "Player uses MedianFinder" << endl;
        sleep(2);
    }
}
void gameLoop(GameField* gameField, Miner* miners[]){
    while(true){
        for(int i = 0; i < NUMBER_OF_MINNING_BOTS;i++){
            system("clear");
            positionAndScorePrinter(gameField,miners);
            gameField->gameFieldPrinter(miners[i],i+1);
            while(true){
                int number = moveOrMine(miners[i]);
                if(number == 1){
                    playerMove(miners[i],gameField);
                    gameField->gameFieldPrinter(miners[i],i+1);
                    sleep(2);
                }
                else{
                    abilityUse(miners[i],gameField);
                    break;
                }
            }
            if(miners[i]->score >= 50){
                gameField->gameFieldReload();
                miners[0]->score = 0;
                miners[1]->score = 0;
            }
        }
    }
}
int main() {
    srand(time(0));
    GameField* gameField = new GameField();
    MinerBotsFabrik* minningBots = new MinerBotsFabrik();
    Miner* miners[NUMBER_OF_MINNING_BOTS];
    minnersChooser(miners,minningBots);
    gameLoop(gameField,miners);
    return 0;
}
