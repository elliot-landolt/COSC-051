#include <iostream>

using namespace std;

int main (){
    int done = 0;
    int userInput;
    while (done == 0)
    {
        cout << "\nPress 1 for painting a wall, Press 2 for mowing the lawn, press 3 for ordering food ";
        cin >> userInput;
        switch (userInput)
        {
        case 0:
            done = 1;
            break;
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
            double duration, cutRate;
            cout << "How long is the lawn? ";
            cin >> length;
            cout << "How wide is the lawn? ";
            cin >> width;
            cout << "At what rate does the mower cut the lawn in sqft/hr? ";
            cin >> cutRate;
            surfArea = length * width;
            duration = surfArea / cutRate;
            cout << "It will take " << duration << " hours to cut the lawn";
            break;
        case 3: 
            double deliveryLength, milesPer, fuelCost, gallons;
            cout << "How far is the delivery in miles? ";
            cin >> deliveryLength;
            cout << "How many miles per gallon does the car get? ";
            cin >> milesPer;
            cout << "What is the fuel cost per gallon? ";
            cin >> fuelCost;
            gallons = deliveryLength / milesPer;
            costTotal = gallons * fuelCost;
            cout << "It will cost " << costTotal << " dollars in gas to make the delivery.";
            break;
        default:
            if (userInput > 3)
            {
                cout << userInput << " ";
                for (int i = 0; i < userInput; i++)
                {
                    cout << "*";
                }
                break;
            }
            else
                cout << "Please enter a valid number";
        }
    }
}
