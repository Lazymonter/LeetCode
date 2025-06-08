#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s) {
    int len = s.length();
    if (len <= 0) {
        return "";
    }
    int ori = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            for (int j = i - 1; j > ori; --j, ++ori) {
                char temp = s[j];
                s[j] = s[ori];
                s[ori] = temp;
            }
            ori = i + 1;
        }
    }
    for (int j = len - 1; j > ori; --j, ++ori) {
        char temp = s[j];
        s[j] = s[ori];
        s[ori] = temp;
    }
    return s;
}

int main() {
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s) << endl;
    return 0;
}