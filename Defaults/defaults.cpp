//
// Created by Muayad Mhanna on 03.04.24.
//

#include "defaults.h"

void firstRow(int number){
    cout << "|  " << number << "   | ";
}
void secondRow(int layer){
    cout << "|  L" << layer << "  | ";
}
void closeRow(){
    cout << " ------ ";
}
char moveChecker(){
    char input;
    while(true){
        cout << "Which way you want to go UP(w)-DOWN(s)-LEFT(a)-RIGHT(d): ";
        cin >> input;
        input = tolower(input);
        if(input == 'w' || input == 's'|| input == 'a' || input == 'd'){
            break;
        }
    }
    return input;
}