#include <iostream>

using namespace std;

int main (){
    int userInput;
    cout << "Press 1 for painting a wall, Press 2 for mowing the lawn, press 3 for ordering food ";
    cin >> userInput;
    switch (userInput)
    {
    case 1:
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
        break;
    
    case 2:

    case 3: 

    default:
        if (userInput > 3)
        {
            cout << userInput << " ";
            for (int i = 0; i < userInput; i++)
            {
                cout << "*";
            }
        }
        else
            cout << "Please enter a valid number";
        break;
    }
}