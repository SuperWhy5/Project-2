#ifndef QA_H
#define QA_H
#include <iostream>

class QA{
    private:
        std::string question = "";

        std::string answer = "";

        static int score;

    public:
        QA();

        QA(std::string q, std::string a);

        std::string getQuestion();

        std::string getAnswer();

        static int getScore();

        int letterCount();

        static void updateScore(int val);
};

#endif
