//2019校招网易游戏笔试题
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


void shuifei(vector<int> & sallist)
{
	vector<int> result;
	for(vector<int>::iterator iter = sallist.begin();iter != sallist.end();iter++)
	{
		int temp = *iter;
		int tax = 0;
		if(temp <= 5000)
		{
			tax = 0;
			result.push_back(tax);
		}
		else
		{
			int over = temp - 5000;
			if(over <= 3000)
			{
				tax = over * 0.03 + 0.5;
			}
			else if(over <= 12000)
			{
				tax = 3000 * 0.03 + ((over - 3000) * 0.1 + 0.5);
			}
			else if(over <= 25000)
			{
				tax = 3000 * 0.03 + 9000 * 0.1 + ((over - 12000) * 0.2 + 0.5);
			}
			else if(over <= 35000)
			{
				tax = 3000 * 0.03 + 9000 * 0.1 + 13000 * 0.2 + ((over - 25000) * 0.25 + 0.5);
			}
			else if(over <= 55000)
			{
				tax = 3000 * 0.03 + 9000 * 0.1 + 13000 * 0.2 + 10000 * 0.25 + ((over - 35000) * 0.3 + 0.5);
			}
			else if(over <= 80000)
			{
				tax = 3000 * 0.03 + 9000 * 0.1 + 13000 * 0.2 + 10000 * 0.25 + 20000 * 0.3 + ((over - 55000) * 0.35 + 0.5);
			}
			else
			{
				tax = 3000 * 0.03 + 9000 * 0.1 + 13000 * 0.2 + 10000 * 0.25 + 20000 * 0.3 + 25000 * 0.35 + ((over - 80000) * 0.45 + 0.5);
			}
			result.push_back(tax);
		}
	}
	for(vector<int>::iterator iter = result.begin();iter != result.end();iter++)
	{
		cout << *iter << endl;
	}
}

int main()
{
	int count = 0;
	int salary;
	vector<int> sallist;
	cin >> count;
	for(int i = 0;i < count;i++)
	{
		cin >> salary;
		sallist.push_back(salary);
	}
	shuifei(sallist);
	return 0;
}
