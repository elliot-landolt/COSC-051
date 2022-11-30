#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iostream> // can remove when finished
#include <algorithm>
#include <iomanip> // may not need, textbook said use but I think it still runs without

using namespace std;

const int numberOfGrades = 7;
ofstream ofs;

class Student // create student structure
{
    private:
    int grades[numberOfGrades];

    public:
    string name;
    int g[numberOfGrades];
    void setGrades (int){
        for (int index = 0; index < numberOfGrades; index++)
        grades[index] = g[index];
    }
    void weightedAverage (Student&, double[]);
    void grade (Student&);
    float weightedScore;
    char finalGrade;
};

void printStudent(Student&);
vector <Student> readStudentsFromFile(double[]);

int main (){
    double weights[numberOfGrades] = {0.02, 0.1, 0.1, 0.14, 0.14, 0.2, 0.3}; // create weights array
    Student student;
    vector <Student> students = readStudentsFromFile(weights);
    ofs.open("P4Output.txt");
    ofs << "In order of entry: " << endl;
    for(Student student : students)
    {
        printStudent(student);
    }
    ofs << "\nSorted by weighted score: " << endl;
    sort(students.begin(), students.end(), [](Student a, Student b){
        return a.weightedScore > b.weightedScore;
    });
    for(Student student : students)
    {
        printStudent(student);
    }
}

void Student::grade (Student& student){
    ofstream ofs;
    ofs.open("P4Output.txt");
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


void printStudent (Student& student){
    ofs << student.name << " Grades: ";

    for (int i = 0; i< 7; i++){
        ofs << student.g[i] << " ";
    }

    ofs << "Weighted Average: " << student.weightedScore;
    ofs << " Final Grade: " << student.finalGrade << endl;
}

vector <Student> readStudentsFromFile(double weights[]){
    ifstream ifs;
    ifs.open("P4Test.txt");

    vector <Student> students;
    string name, input;
    
    while (ifs >> name) {
        Student student;
        student.name = name;
        for (int i = 0; i < 7; i++)
        {
            ifs >> input;
            student.g[i] = stoi(input);
        }
        
        for(int i =0; i <7; i++)
        {
            cout << student.g[i] << endl;
        }

        student.weightedAverage(student, weights);
        student.grade(student);
        student.setGrades(student.g[numberOfGrades]);
        students.push_back(student);
    }
    return students;
}

void Student::weightedAverage (Student&student, double weights[]){
    double avg = 0;
    for (int i =0; i < numberOfGrades; i++){
    avg += (student.grades[i] * weights[i]);
    }
    student.weightedScore = avg;
}