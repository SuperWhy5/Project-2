#include <iostream>
#include "QA.h"

int QA::score;

QA::QA(){}

QA::QA(std::string q, std::string a) : question(q), answer(a) {}

//Get Methods.
std::string QA::getQuestion(){
    return question;
}

std::string QA::getAnswer(){
    return answer;
}

int QA::getScore(){
    return score;
}

//Counts the amount of letters in question and answer combined.
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

//Updates score by the value(val) given. Will not go bellow 0.
void QA::updateScore(int val){

    QA::score += val;

    if(QA::score < 0){
        QA::score = 0;
    }
}
