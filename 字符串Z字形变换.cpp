#include<iostream>
#include<string>

using namespace std;

string convert(string s,int numRows)
{
	if(numRows == 1)
	{
		return s;
	}
	string result;
	int group = numRows + (numRows - 2)
	int gaps = group - 2;
	for(int i = 0;i < numRows;i++)
	{
		string temp = "";
		if(i == 0)
		{
			for(int j = 0;j < s.length();j = j + group)
			{
				temp += s[j];
			}
		}
		else if(i == numRows - 1)
		{
			for(int j = i;j < s.length();j = j + group)
			{
				temp += s[j];
			}
		}
		else
		{
			for(int j = i;j < s.length();j = j + group)
			{
				if(j + gaps < s.length())
				{
					temp = temp + s[j] + s[j + gaps];
				}
				else
				{
					temp = temp + s[j];
				}
			}
			gaps = gaps - 2;
		}
		result += temp;
	}
	return result;
}
