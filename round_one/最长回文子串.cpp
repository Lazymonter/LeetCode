//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
//输入: "babad"
//输出: "bab"
//注意: "aba"也是一个有效答案。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Manacher
string longestPalindrome(string s){
    if(s == "") return s;
    string s_pro = "$";
    for(char c : s){
        s_pro.push_back(c);
        s_pro.push_back('#');
    }
    s_pro.push_back('&');
    int len = s_pro.length();
    vector<int> p(len,0);
    int max_len = -1,mid_point = -1;
    int pos = 0,maxright = 0;
    for(int i = 1;i < len;i++){
        if(i < maxright){
            p[i] = min(p[(pos << 1) - i],maxright - i);
        }
        else{
            p[i] = 1;
        }
        while(s_pro[i - p[i]] == s_pro[i + p[i]]){
            p[i]++;
        }
        if(maxright < i + p[i]){
            pos = i;
            maxright = i + p[i];
        }
        //max_len = max(max_len,p[i] - 1);
        if(max_len < p[i] - 1){
            mid_point = i;
            max_len = p[i] - 1;
        }
    }
    string temp = s_pro.substr(mid_point - max_len,(max_len << 1) + 1);
    string res = "";
    for(char c : temp){
        if(c != '#'){
            res.push_back(c);
        }
    }
    return res;
}
//暴力遍历法
string longestPalindrome_sss(string s) {
    int length = s.length();
 	string result = "";
 	int resultlen = 0;
 	int flag = 0;
 	string max = "";
    if(length == 1)
    {
        return s;
    }
 	for(int i = 1;i < length;i++)
 	{
 		if(s[i] == s[i - 1])
 		{
 			resultlen += 2;
 			result += s[i];
 			result = s[i] + result;
 			int j = i + 1;
 			int k = i - 2;
 			while(j < length && k >= 0)
 			{
 				if(s[j] == s[k])
 				{
 					resultlen += 2;
 					result += s[j];
 					result = s[k] + result;
 				}
 				else
 				{
 					break;
 				}
                j++;
                k--;
 			}
 			if(flag < resultlen)
 			{
 				max = result;
 				flag =resultlen;
 			}
 			resultlen = 0;
 			result = "";
 		}
    }
        if(max == s)
        {
            return s;
        }
    for(int i = 1;i < length;i++)
 	{
 		if(s[i - 1] == s[i + 1])
 		{
 			resultlen += 3;
 			result += s[i];
 			result += s[i + 1];
 			result = s[i - 1] + result;
 			int j = i + 2;
 			int k = i - 2;
 			while(j < length && k >= 0)
 			{
 				if(s[j] == s[k])
 				{
 					resultlen += 2;
 					result += s[j];
 					result = s[k] + result;
 				}
 				else
 				{
 					break;
 				}
                j++;
                k--;
 			}
 			if(flag < resultlen)
 			{
 				max = result;
 				flag =resultlen;
 			}
 			resultlen = 0;
 			result = "";
 		}
 	}
        if(flag == 0)
        {
            string re = "";
            re += s[0];
            return re;
        }
    
 	return max;
}
