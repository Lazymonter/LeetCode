//来自网易游戏研发笔试题
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void updateTime(vector<string> & vec)
{
	for(vector<string>::iterator iter = vec.begin();iter != vec.end();iter++)
	{
		string temp = *iter;
		if((temp[0] - '0') > 2 || ((temp[0] - '0') == 2 && (temp[1] - '0') > 3))
		{
			temp[0] = '0';
		}
		if((temp[3] - '0') > 5)
		{
			temp[3] = '0';
		}
		if((temp[6] - '0') > 5)
		{
			temp[6] = '0';
		}
		*iter = temp;
 	}
}

int main()
{
	vector<string> vec;
	int T;
	string inputtemp;
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		cin >> inputtemp;
		vec.push_back(inputtemp);
	}
	updateTime(vec);
	for(vector<string>::iterator iter = vec.begin();iter != vec.end();iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}
