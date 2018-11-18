#include <iostream>
using std::cout;
using std::cin;
int main() {
    int count;
    cin >> count;
    for (int i = 0; i < count; i ++){
        for (int j = 0; j < i; j ++){
            cout << "*";
        }
        cout << std::endl;
    }
    return 0;
}