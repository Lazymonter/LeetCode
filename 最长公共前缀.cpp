#include <iostream>
#include <string>
#include <vector>

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()){
        return "";
    }
    string common = strs[0];
    for (int i = 1; i < strs.size(); i++){
        string temp = "";
        for (int j = 0; j < strs[i].size(); j++){
           if (strs[i][j] == common[j] && j < common.size()){
               temp += strs[i][j];
           }
           else{
               break;
           } 
        }
        common = temp;
        if (!common.size()){
            break;
        }
    }

    return common;
        
}


string longestCommonPrefix2(vector<string>& strs) {
    if (strs.empty()){
        return "";
    }
    string common = strs[0];
    for (int i = 1; i < strs.size(); i++){
        int size = common.size() > strs[i].size() ? strs[i].size() : common.size();
        int loc = size;
        for (int j = 0; j < size; j++){
           if (strs[i][j] != common[j]){
               loc = j;
               break;
           }
        }
        common = common.substr(0, loc);
        if (!common.size()){
            return "";
        }
    }

    return common;
        
}
int main(){
    vector<string> v1,v2;
    v1.push_back("flower");
    v1.push_back("flow");
    v1.push_back("flight");
    v2.push_back("dog");
    v2.push_back("rarecar");
    v2.push_back("car");
    cout << longestCommonPrefix(v1) << endl;
    cout << longestCommonPrefix(v2) << endl;
    return 0;
}
