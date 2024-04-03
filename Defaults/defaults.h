//
// Created by Muayad Mhanna on 03.04.24.
//

#ifndef DEEPMINER_DEFAULTS_H
#define DEEPMINER_DEFAULTS_H
#define X_AND_Y_SIZE 5
#define Z_SIZE 10
#define NUMBER_OF_BOTS 3
#pragma once
#include <iostream>
using namespace std;

typedef struct coordinates{
    int x;
    int y;
} coordinates;

void firstRow(int number);
void secondRow(int layer);
void closeRow();
char moveChecker();



#endif //DEEPMINER_DEFAULTS_H
