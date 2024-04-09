//
// Created by Muayad Mhanna on 03.04.24.
//

#ifndef DEEPMINER_DEFAULTS_H
#define DEEPMINER_DEFAULTS_H
#define X_AND_Y_SIZE 5
#define Z_SIZE 10
#define NUMBER_OF_BOTS 3
#define NUMBER_OF_MINNING_BOTS 2
#pragma once
#include <iostream>
#include <vector>
using namespace std;


void firstRow(int number);
void secondRow(int layer);
void closeRow();
char moveChecker();
void getAbilityInfo(std::string ability);



#endif //DEEPMINER_DEFAULTS_H
