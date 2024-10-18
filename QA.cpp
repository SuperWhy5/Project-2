#include <iostream>
#include "QA.h"

int QA::score;

QA::QA(){}

QA::QA(std::string q, std::string a) : question(a), answer(a) {}

std::string QA::getQuestion(){
    return question;
}

std::string QA::getAnswer(){
    return answer;
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

    score += val;

    if(score < 0){
        score = 0;
    }
}
