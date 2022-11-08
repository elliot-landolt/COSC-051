#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int roomCapacity = 45;
const int numberOfGrades = 7;
ofstream ofs;


struct Student // create student structure
{
    string name;
    int grades[numberOfGrades]; // create grades array
    float weightedScore;
    char finalGrade;
};

void weightedAverage (Student&, double[]);
void grade (Student&);
vector <Student> readStudentsFromFile(double[]);
void printStudent (Student&);
void sortStudent (Student&);

int main (){
    double weights[numberOfGrades] = {0.02, 0.1, 0.1, 0.14, 0.14, 0.2, 0.3}; // create weights array
    Student student;
    vector <Student> students = readStudentsFromFile(weights);
    ofs.open("P3Output.txt");
    ofs << "In order of entry: " << endl;
    for(Student student : students)
    {
        printStudent(student);
    }
    ofs << "Sorted by weighted score: " << endl;
    for(Student student : students)
    {
        sortStudent(student);
    }
}

void grade (Student& student){
    ofstream ofs;
    ofs.open("P3Output.txt");

    for (int i = 0; i < roomCapacity; i++)
    {
        if (student.weightedScore >= 90){
            student.finalGrade = 65;
        }
        else if (student.weightedScore >= 80 and student.weightedScore < 90){
            student.finalGrade = 66;
        }
        else if(student.weightedScore >= 70 and student.weightedScore < 80){
            student.finalGrade = 67;
        }
        else if(student.weightedScore >= 60 and student.weightedScore < 70){
            student.finalGrade = 68;
        }
        else if(student.weightedScore >= 0 and student.weightedScore < 60){
            student.finalGrade = 70;
        }
        else
        {
            ofs << "Invalid Score";
        }
    } 
}

void printStudent (Student& student){
    ofs << student.name << " Grades: ";

    for (int i = 0; i< 7; i++){
        ofs << student.grades[i] << " ";
    }

    ofs << "Weighted Average: " << student.weightedScore;
    ofs << " Final Grade: " << student.finalGrade << endl;
}

void sortStudent (Student& student){
    ofs << student.name << " Grades: ";
    for (int i = 0; i< 7; i++){
        ofs << student.grades[i] << " ";
    }
    ofs << "Weighted Average: " << student.weightedScore;
    ofs << " Final Grade: " << student.finalGrade << endl;
}

vector <Student> readStudentsFromFile(double weights[]){
    ifstream ifs;
    ifs.open("P3Test.txt");

    vector <Student> students;
    string name, input;
    
    while (ifs >> name) {
        Student student;
        student.name = name;
        for (int i = 0; i < 7; i++)
        {
            ifs >> input;
            student.grades[i] = stoi(input);
        }
        weightedAverage(student, weights);
        grade(student);
        students.push_back(student);
    }
    return students;
}

void weightedAverage (Student&student, double weights[]){
    double avg = 0;
    for (int i =0; i < numberOfGrades; i++){
    avg += (student.grades[i] * weights[i]);
    }
    student.weightedScore = avg;
}