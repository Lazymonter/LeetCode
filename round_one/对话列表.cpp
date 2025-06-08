//来自网易游戏研发笔试题
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int count = 0;
	int num = 0;
	vector<vector<int> > result;
	vector<vector<int> > begin;
	cin >> count;
	for(int x = 0;x < count;x++)
	{
		cin >> num;
		vector<int> temp1;
		int temp2 = 0;
		for(int y = 0;y < num;y++)
		{
			cin >> temp2;
			temp1.push_back(temp2);
		}
		begin.push_back(temp1);
	}
	for(int i = 0;i < count;i++)//1 100 1000 1000 100 1
	{
		vector<int> value;
		for(vector<int>::iterator iter = begin[i].begin();iter != begin[i].end();iter++)
		{
			int temp = *iter;
			if(find(value.begin(),value.end(),temp) == value.end())
			{
				value.push_back(temp);
			}
			else
			{
				vector<int>::iterator loc = find(value.begin(),value.end(),temp);
				value.erase(loc);
				value.push_back(temp);
			}
		}
		result.push_back(value);
	}
	for(int m = 0;m < result.size();m++)
	{
		for(int n = result[m].size() - 1;n >= 0;n--)
		{
			if(n == result[m].size() - 1)
			{
				cout << result[m][n];
			}
			else
			{
				cout << " " << result[m][n];
			}
		}
	}
	return 0;
}
