#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ofstream outFile;
ifstream inFile;
double manage;

int main(){
    inFile.open("test.txt");
    outFile.open("test2.txt");
    inFile >> manage;
    outFile << manage;
}