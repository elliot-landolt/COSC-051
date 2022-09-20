#include <string>
#include <iostream>

using namespace std;

int main(){

    string name;
    cout << "test\n";
    getline(cin, name);
    cout << name;
    cin >> name;
    cout << name;
}