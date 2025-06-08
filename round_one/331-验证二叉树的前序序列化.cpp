/*
栈
*/
#include <iostream>
#include <string>

using namespace std;

bool isValideSerialization(string preorder) {
    int len = preorder.length();
    int i = 0;
    int spaceSum = 1;

    while (i < len) {
        if (spaceSum == 0) {
            return false;
        } 

        if (preorder[i] == '#') {
            spaceSum--;
            i++;
        } else if (preorder[i] == ',') {
            i++;
        } else {
            while (i < len && preorder[i] != ',') {
                i++;
            }
            spaceSum += 1;
        }
    }
    return spaceSum == 0;
}

int main() {
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << isValideSerialization(preorder) << endl;
    return 0;
}