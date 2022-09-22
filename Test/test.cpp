#include <string>
#include <iostream>

using namespace std;

int main(){
    int num = 5;
    string name;
    cout << "test\n";
    getline(cin, name);
    if (num == 4 || name == "Elliot"){
        cout << "it worked";
        return 0;
    }
    cout << name;
    cin >> name;
    cout << name;
}