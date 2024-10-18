/*****************************************************************************************
  Name: Ja'Vien Elmore
  My Class: CPSC 1021
  Date: 10/10/2024
  Desc: This program will allows a player to answer quiz questions. Questions are asked in
  a random order from a database.txt file. 
  Time: 10 hours
**********************************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "QA.h"
using namespace std;

int main(int argc, char *argv[]){

  srand(unsigned(time(0)));

  ifstream inFile(argv[1]);

  // int currentLineNumber = 1;
  // int questionLine[] = {1,4,7,10,14};
  // int answerLine[] = {};
  std::string line, question, answer;
  std::vector<QA> quizVector;

  std::string QA1;

  // QA q1("What?","Nothing..");

  while(getline(inFile,line)){
    if(line.rfind("Question:", 0) == 0){
      question = line;
    }
    else if(line.rfind("Answer:", 0) == 0){
      answer = line.substr(8);
      
      QA qa(question, answer);

      quizVector.push_back(qa);

    }
    else{
      question += " " + line;
    }
  }

  random_shuffle(quizVector.begin(), quizVector.end());

  for (QA& qa : quizVector) {
      string userChoice;
      cout << qa.getQuestion() << endl;
      cout << "Type in your answer: ";
      getline(cin, userChoice);
      if(userChoice == qa.getAnswer()){
        qa.updateScore(1);
        cout << "Correct!" <<"\nCurrent score: " << qa.getScore() << "\n\n";
      }
      else{
        qa.updateScore(-1);
        cout << "Wrong! Correct answer: " << qa.getAnswer() << endl;
        cout << "Current score: " << qa.getScore() << "\n\n";
      }
  }

  
  inFile.close();

  return 0;
}