//最简单的想法，输入数据为1-3999因此将4位中9个数字分别表示出来即可
#include<iostream>
#include<string>

using namespace std;
string intToRoman(int num) {
	string s[4][9] = {{"I","II","III","IV","V","VI","VII","VIII","IX"},
					  {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
					  {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
					  {"M","MM","MMM"}};
	int temp = num;
	int count = 0;
	string result = "";
	while(temp)
	{
		int temp1 = temp % 10;
		if(temp1)
		{
			result = s[count][temp1 - 1] + result;
		}
		temp = temp / 10;
		count++;
	}
	return result;        
}


//
