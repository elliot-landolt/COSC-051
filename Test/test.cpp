#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ofstream outFile;
ofstream inFile;
char manage;

int main(){
    inFile.open("test.dat");
    outFile.open("test2.txt");
    inFile >> manage;
    outFile << "this is a working test";
}