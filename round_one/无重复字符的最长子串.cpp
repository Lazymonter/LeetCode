//给定一个字符串，找出不含有重复字符的最长子串的长度。
//示例：
//给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
//给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
//给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring_first(string s) {
    string max = "";
    int longest = 0;
    for(int i = 0;i < s.length();i++)
    {
        string temp = "";
        temp += s[i];
        for(int j = i + 1;j < s.length();j++)
        {
            if(temp.find(s[j]) == -1)
            {
                temp += s[j];
            }
            else{
                if(temp.length() > longest)
                {
                    longest = temp.length();
                        max = temp;
                }
                    break;
            }
            if(j == s.length() - 1)
            {
                if(temp.length() > longest)
                {
                    longest = temp.length();
                        max = temp;
                }
            }
            
        }
        if(temp.length() == s.length())
        {
            max = s;
            longest = s.length();
            break;
        }
    }
    return longest;
}

int lengthOfLongestSubstring(string s){
    unordered_set<char> visited;
    int len = s.length();
    int right = -1,res = 0;
    for(int i = 0;i < len;i++){
        if(i != 0){
            visited.erase(s[i - 1]);
        }
        while(right + 1 < len && !visited.count(s[right + 1])){
            visited.insert(s[right + 1]);
            ++right;
        }
        res = max(res,right - i + 1);
    }
    return res;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}