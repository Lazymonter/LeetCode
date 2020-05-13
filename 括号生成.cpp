#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> generateParenthesis(int n){
    if(n == 0) {
        return {};
    }
    else if(n == 1) {
        return {"()"};
    }
    else{
        vector<vector<string>> result(n + 1);
        result[0] = {""};
        result[1] = {"()"};
        for(int i = 2;i <= n;i++){
            for(int j = 0;j < i;j++){
                for(string p : result[j]){
                    for(string q : result[i - j - 1]){
                        string str = "(" + p + ")" + q;
                        result[i].push_back(str);
                    }
                }
            }
        }
        sort(result[n].begin(), result[n].end());
        return result[n];
    }
}

void printVec(vector<string> &result){
    for(vector<string>::const_iterator iter = result.begin();iter != result.end();iter++){
        cout << *iter << endl;
    }
}

int main(){
    int n = 4;
    vector<string> result = generateParenthesis(n);
    printVec(result); 
    return 0 ;
}