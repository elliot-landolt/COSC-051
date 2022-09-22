#include <iostream>

using namespace std;

int main (){
    int userInput;
    cout << "Press 0 for painting a wall, press 1 for ordering food ";
    cin >> userInput;
    if (userInput == 0){
        double length, width, sqQuart, costQuart, costTotal, surfArea, totalQuart;
        cout << "How long is the wall? ";
        cin >> length;
        cout << "How wide is the wall? ";
        cin >> width;
        cout << "How many square feet does each quart of paint cover? ";
        cin >> sqQuart;
        cout << "How much does each quart cost? ";
        cin >> costQuart;
        surfArea = length * width;
        totalQuart = surfArea / sqQuart;
        costTotal = totalQuart * costQuart;
        cout << "You will need " << totalQuart << " quarts of paint to cover the wall. It will cost " 
            << costTotal << " dollars to paint the wall";
    }
    else if (userInput == 1){

    }

    else if (userInput == 2){

    }
    else {
        cout << "Please enter a valid number (0, 1, 2)";
    }
}