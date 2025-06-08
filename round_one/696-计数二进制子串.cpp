#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countBinarySubstrings(string s) {
    int cur = 0, last = 0, result = 0;
    int len = s.length();
    while(cur < len) {
        char c = s[cur];
        int count = 0;
        while(cur < len && s[cur] == c) {
            ++cur;
            ++count;
        }
        result += min(count, last);
        last = count;
    }
    return result;
     
}

int main() {
    string s = "00111011";
    cout << countBinarySubstrings(s) << endl;
    return 0;
}