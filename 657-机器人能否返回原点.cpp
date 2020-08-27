#include <iostream>
#include <string>

using namespace std;

bool judgCircle(string moves) {
    int x = 0, y = 0;
    for (auto &&c : moves) {
        if (c == 'R') {
            ++x;
        } else if (c == 'L') {
            --x;
        } else if (c == 'U') {
            ++y;
        } else {
            --y;
        }
    }
    return (x == 0 && y == 0);
}

int main() {
    string s = "RRUUDLLDL";
    cout << judgCircle(s) << endl;
    return 0;
}