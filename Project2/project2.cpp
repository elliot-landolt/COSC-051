#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

ofstream outFile;
ifstream inFile;

int main (){
    int done = 0;
    int userInput;
    inFile.open("input.txt");
    outFile.open("output.txt");
    while (done == 0)
    {
        cout << "\nPress 1 for painting a wall, Press 2 for mowing the lawn, press 3 for ordering food " << endl;
        inFile >> userInput;
        switch (userInput)
        {
        case 0:
            done = 1;
            inFile.close();
            outFile.close();
            break;
        case 1:
            double length, width, sqQuart, costQuart, costTotal, surfArea, totalQuart;
            cout << "How long is the wall? ";
            inFile >> length;
            cout << "How wide is the wall? ";
            inFile >> width;
            cout << "How many square feet does each quart of paint cover? ";
            inFile >> sqQuart;
            cout << "How much does each quart cost? ";
            inFile >> costQuart;
            surfArea = length * width;
            totalQuart = ceil(surfArea / sqQuart);
            costTotal = totalQuart * costQuart;
            outFile << "You will need " << totalQuart << " quarts of paint to cover the wall. It will cost " 
                << costTotal << " dollars to paint the wall" << endl;
            break;
    
        case 2:
            double duration, cutRate, minDuration;
            cout << "How long is the lawn? ";
            inFile >> length;
            cout << "How wide is the lawn? ";
            inFile >> width;
            cout << "At what rate does the mower cut the lawn in sqft/hr? ";
            inFile >> cutRate;
            surfArea = length * width;
            duration = surfArea / cutRate;
            minDuration = duration * 60;
            outFile << "It will take " << minDuration << " minutes to cut the lawn" << endl;
            break;
        case 3: 
            double deliveryLength, milesPer, fuelCost, gallons;
            cout << "How far is the delivery in miles? ";
            inFile >> deliveryLength;
            cout << "How many miles per gallon does the car get? ";
            inFile >> milesPer;
            cout << "What is the fuel cost per gallon? ";
            inFile >> fuelCost;
            gallons = deliveryLength / milesPer;
            costTotal = gallons * fuelCost;
            outFile << "It will cost " << costTotal << " dollars in gas to make the delivery." << endl;
            break;
        default:
            if (userInput > 3)
            {
                outFile << userInput << " ";
                for (int i = 0; i < userInput; i++)
                {
                    outFile << "*";
                }
                outFile << endl;
                break;
            }
            else
                cout << "Please enter a valid number";
        }
    }
}
