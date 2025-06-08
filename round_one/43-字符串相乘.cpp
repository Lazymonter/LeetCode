#include <iostream>
#include <string>
#include <vector>


using namespace std;

string bigIntSum(string num1, string num2) {
    string result = "";
    int len1 = num1.length() - 1;
    int len2 = num2.length() - 1;
    int up = 0;
    while(len1 >= 0 || len2 >= 0 || up > 0) {
        int op1 = 0, op2 = 0;
        if(len1 >= 0) {
            op1 = num1[len1] - '0';
        }
        if(len2 >= 0) {
            op2 = num2[len2] - '0';
        }
        int sum = op1 + op2 + up;
        up = sum / 10;
        result = to_string(sum % 10) + result;
        --len1;
        --len2;
    }
    return result;
}

string multiSingleAndMul(int single, string num2) {
    if(single == 0 || num2 == "0") {
        return "0";
    }
    string result = "";
    int len = num2.length() - 1;
    int up = 0;
    while(len >= 0 || up > 0) {
        int op1 = 0;
        if(len >= 0) {
            op1 = num2[len] - '0';
        }
        int product = op1 * single + up;
        up = product / 10;
        result = to_string(product % 10) + result;
        --len;
    }
    return result;
}

string multiply(string num1, string num2) {
    string result = "0";
    if(num1 == "0" || num2 == "0") {
        return "0";
    }
    int len = num1.length() - 1;
    for(int i = 0;i <= len; ++i) {
        string product = multiSingleAndMul((num1[len - i] - '0'), num2);
        for(int j = 0; j < i; j++) {
            product += "0";
        }
        result = bigIntSum(result, product);
    }
    return result;

}

int main() {
    string num1 = "9133";
    string num2 = "0";
    cout << multiply(num1, num2) << endl;
    return 0;
}