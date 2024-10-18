#include <iostream>
#include <sstream>
#include <iomanip>


std::string buildResultString(int questions, int correct, int wrong){
    int finalScore = correct - wrong;
    if(finalScore < 0){
        finalScore = 0;
    }
     std::stringstream ss;

     ss << std::left << "Number of questions: " << questions << "\n"
        << std::left << "Number of correct answers: " << correct << "\n"
        << std::left << "Number of wrong answers: " << wrong << "\n"
        << std::left << "Final score: " << finalScore;

    return ss.str();
}
