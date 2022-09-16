#include <iostream>

using namespace std;

int main (){
    int length, width, sqQuart, costQuart, costTotal;
    int surfArea = length * width;
    int totalQuart = surfArea / sqQuart;
    int costTotal = totalQuart * costQuart;
    cout << "How long is the wall? ";
    cin >> length;
    cout << "How wide is the wall? ";
    cin >> width;
    return 0;
}