#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords_s(string s) {
    string result = "";
    string result_temp = "";
    for(char c : s){
        if(c == ' '){
            if(result_temp != ""){
                if(result == "")
                {
                    result = result_temp;
                    result_temp = ""; 
                }
                else{
                    result = result_temp + " " + result;
                    result_temp = "";
                }    
            }
            else{
                continue;
            }    
        }
        else{
            result_temp.push_back(c);
        }
    }
    if(result_temp != "")
    {
        if(result == "")
        {
            result = result_temp;
        }
        else{
            result = result_temp + " " + result;
        }    
    }
    return result;
}

string reverseWords(string s){
    reverse(s.begin(), s.end());
    int n = s.size();
    int idx = 0;
    for(int start = 0; start < n; start++){
        if(s[start] != ' '){
            if(idx != 0){
                s[idx++] = ' ';
            }
        }
        int end = start;
        while(end < n && s[end] != ' '){
            s[idx++] = s[end++];
        }
        reverse(s.begin() + idx - (end - start), s.begin() + idx);
        start = end;
    }
    s.erase(s.begin() + idx,s.end());
    return s;
}

int main(int argc, char* argv[]){
    string s = " ssr  ssr  ssr ";
    string result = reverseWords(s);
    cout << result << endl;
    cout << result.length() << endl;
    return 0;
}