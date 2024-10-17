#include <iostream>
#include "QA.h"

QA::QA(){}

QA::QA(std::string q, std::string a) : question(a), answer(a) {}

std::string QA::getQuestion(){

}

std::string QA::getAnswer(){

}

int QA::getScore(){
    return score;
}

int QA::letterCount(){

    int count = 0;

    for(char i : question){
        if(std::isalpha(i)){
            count++;
        }
    }
    for(char i : answer){
        if(std::isalpha(i)){
            count++;
        }
    }

    return count;
}

void QA::updateScore(int val){

}
