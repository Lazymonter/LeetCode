#include <iostream>
#include <vector>
#include <string>

#include "utils/myutil.hpp"

using namespace std;

vector<vector<int>> largeGroupPositions(string s) {
    int len = s.length();
    if (len == 0) {
        return {};
    }
 
    int curLength = 1;
    vector<vector<int>> result;
    for (int i = 0; i < len; ++i) {
        if (i == len - 1 || s[i] != s[i + 1]) {
            if (curLength >= 3) {
                vector<int> temp = {i - curLength + 1, i};
                result.emplace_back(temp);
            }
            curLength = 1;
        } else {
            curLength++;
        }
    }

    return result;
}

int main() {
    string s = "abcdddeeeeaabbbcd";
    string s2 = "abc";
    vector<vector<int>> result = largeGroupPositions(s);
    vector<vector<int>> result2 = largeGroupPositions(s2);
    printMultiVec(result);
    printMultiVec(result2);
    return 0;
}