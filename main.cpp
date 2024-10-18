/*****************************************************************************************
  Name: Ja'Vien Elmore
  My Class: CPSC 1021
  Date: 10/10/2024
  Desc: This program will allows a player to answer quiz questions. Questions are asked in
  a random order from a database.txt file. The player (you the user) can score points if 
  they get the answer correct and lose points if they get the answer wrong. At the end of
  the program the game results are show.
  Time: 10 hours
**********************************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "QA.h"
#include "buildResultString.h"
using namespace std;

int main(int argc, char *argv[]){

  srand(unsigned(time(0)));

  //Gets file from the command line.
  ifstream inFile(argv[1]);

  //create variables to capture the question and answer from database.txt.
  std::string line, question, answer;

  //create vector named "quizVector"
  std::vector<QA> quizVector;

  /*This while loop:
    - Reads each line in database.txt.
    - Assigns the Questions to the question variable.
    - Assigns the Answer to the answer variable.
    - Creates a "qa" object that passes in question & answer.
    - Puts each object into the vector.
  */
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

  //Close the file.
  inFile.close();

  /*Utilizing "random_shuffle" function to randomize
    the question & answer pairs.*/
  random_shuffle(quizVector.begin(), quizVector.end());

  //initializing the variables needed for buildResultString().
  int numQuestions=0, numCorrect=0, numWrong=0;

  /*This for loop:
    - Asks the player a question.
    - Recieves their answer.
    - Updates the score depending if correct(+1) or incorrect(-1).
    - Tells the user if they are correct or not, if not they will
      also be shown the correct answer.
    - Lastly it tells the user the score.
  */
  for (QA& qa : quizVector) {
      string userChoice;
      cout << qa.getQuestion() << endl;

      //incremented by 1 to for buildResultString()
      numQuestions++;
      cout << "Type in your answer: ";
      getline(cin, userChoice);
      if(userChoice == qa.getAnswer()){
        qa.updateScore(1);
        cout << "Correct!" <<"\nCurrent score: " << qa.getScore() << "\n\n";

        //incremented by 1 to for buildResultString()
        numCorrect++;
      }
      else{
        qa.updateScore(-1);
        cout << "Wrong! Correct answer: " << qa.getAnswer() << endl;
        cout << "Current score: " << qa.getScore() << "\n\n";

        //incremented by 1 to for buildResultString()
        numWrong++;
      }
  }

  //Print out game results to the user.
  cout << buildResultString(numQuestions,numCorrect,numWrong);

  return 0;
}