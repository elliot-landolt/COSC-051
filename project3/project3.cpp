#include <fstream>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

ofstream outFile;
ifstream inFile;

const int roomCapacity = 45;
char letterGrade;
char grade(float score); // create function to calculate letter grade
float weightedScore(); // create function to calculate weighted grade

int main (){
    grade(52);
    cout << letterGrade;
}

float weightedScore (){


    return 0;
}

char grade (float score){
    if (score >= 90){
        letterGrade = 65;
    }
    else if (score >= 80 and score <= 89){
        letterGrade = 66;
    }
    else if(score >= 70 and score <= 79){
        letterGrade = 67;
    }
    else if(score >= 60 and score <= 69){
        letterGrade = 68;
    }
    else if(score >= 0 and score <= 59){
        letterGrade = 70;
    }
    else
    {
        cout << "Please enter a valid score";
        return 0;
    }
    return letterGrade;
}