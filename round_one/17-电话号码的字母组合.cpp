#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "utils/myutil.hpp"

using namespace std;
//回溯法
void backtrace(vector<string> &combinations, const unordered_map<char, string> &phoneMap, const string &digits, int index, string &combination) {
    if (index == digits.length()) {
        combinations.push_back(combination);
    } else {
        char digit = digits[index];
        string letters = phoneMap.at(digit);
        for (auto && letter : letters) {
            combination.push_back(letter);
            backtrace(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }
    vector<string> combinations;
    unordered_map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string combination;
    backtrace(combinations, phoneMap, digits, 0, combination);
    return combinations;
}

int main(){
    string s = "23";
    vector<string> result = letterCombinations(s);
    printSingleVec(result);
    return 0;
}