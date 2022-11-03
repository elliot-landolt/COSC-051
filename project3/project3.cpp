#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

ofstream ofs;
ifstream ifs;
const int roomCapacity = 45;

struct Student // create student structure
{
    string name;
    int grades[7]; // create grades array
    float weightedScore;
    char finalGrade;
};

int main (){
    ifs.open("P3Test.txt");
    ofs.open("P3output.txt");
    double weights[7] = {0.02, 0.1, 0.1, 0.14, 0.14, 0.2, 0.3}; // create weights array
    Student student;

}

void weightedAverage (Student&student, double weights[]){
    double avg = 0;
    for (int i =0; i < 7; i++){
    avg += student.grades[i] * weights[i];
    }
}

void grade (Student&student){
    for (int i = 0; i < roomCapacity; i++)
    {
        if (student.weightedScore >= 90){
         student.finalGrade = 65;
    }
    else if (student.weightedScore >= 80 and student.weightedScore <= 89){
        student.finalGrade = 66;
    }
    else if(student.weightedScore >= 70 and student.weightedScore <= 79){
        student.finalGrade = 67;
    }
    else if(student.weightedScore >= 60 and student.weightedScore <= 69){
        student.finalGrade = 68;
    }
    else if(student.weightedScore >= 0 and student.weightedScore <= 59){
        student.finalGrade = 70;
    }
    else
    {
        ofs << "Invalid Score";
    }
    } 
}

vector <Student> readStudentsFromFile(double weights[]){
    vector <Student> students;
    string name;
    while (ifs >> name) {
        Student student;
        student.name = name;
        for (int i = 0; i < 7; i++)
        {
            ifs >> student.grades[i];
        }
        weightedAverage(student, weights);
        grade(student);
        students.push_back(student);
    }
    return students;
}

void printStudent (Student&student){
    ofs << student.name << "Grades: ";
    for (int grade : student.grades){
        ofs << grade << " ";    
    }
    ofs << "Weighted Average: " << student.weightedScore;
    ofs << "Final Grade: " << student.finalGrade << endl;

}