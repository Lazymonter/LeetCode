//回文数判断
//方法一转换为字符串
#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include <algorithm>

using namespace std;
bool isPalindrome(int x) {
	stringstream ss;
	ss << x;
	string s1 = ss.str();
	string s2 = s1;
	reverse(s2.begin(),s2.end());
	return s1 == s2 ? true : false;       
}

//直接数字倒序
bool isPalindrome(int x) {
	int temp = x;
	int reversex = 0;
	if(x < 0)
		return false;
	while(temp)
	{
		reversex = reversex * 10 + temp % 10;
		temp  = temp / 10;
	}       
	return reversex == x ? true : false;
}
