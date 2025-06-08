#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(string &s,int left,int right){
    while(left < right){
        if(s[left++] != s[right--]){
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s){
    int left = 0,right = s.length() - 1;
    while(left < right){
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else{
            return checkPalindrome(s,left,right - 1) || checkPalindrome(s,left + 1,right);
        }
    }
    return true;
}

int main(){
    string s = "ebcbbececabbacecbbcbe";
    cout << validPalindrome(s) << endl;
    return 0;
}