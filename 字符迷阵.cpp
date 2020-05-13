//来自网易游戏研发笔试题
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void searchWord()
{
	vector<vector<char> > input;//字符集
	vector<string> target;//目标串
	int total;//总次数
	vector<int> result;
	cin >> total;
	int **num = new int*[total];
	for(int i = 0;i < total;i++)
	{
		num[i] = new int[2];
	}
	for(int i = 0;i < total;i++)
	{
		cin >> num[i][0] >> num[i][1];
		vector<char> temp;
		for(int j = 0;j < num[i][0];j++)
			for(int k = 0;k < num[i][1];k++)
			{
				char temp1;
				cin >> temp1;
				temp.push_back(temp1);
			}
		input.push_back(temp);
		string temp2 = "";
		cin >> temp2;
		target.push_back(temp2);

	}
	for(int i = 0;i < total;i++)
	{
		string test = target[i];
		int len = test.length();
		int rows = num[i][0];
		int columns = num[i][1];
		int count = 0;
		for(int j = 0;j < rows;j++)
		{
			for(int k = 0;k < columns;k++)
			{
				if(input[i][j * columns + k] == test[0])
				{
					vector<string> tep;
					int m = j,n = k;
					string temp3 = "";
					temp3 += input[i][j * columns + k];
					for(int x = 0;x < len - 1;x++)
					{
						m++;
						if(m < rows && n < columns)
						{
							temp3 += input[i][m * columns + n];
						}
					}
					tep.push_back(temp3);
					m = j;
					n = k;
					temp3 = "";
					temp3 += input[i][j * columns + k];
					for(int y = 0;y < len - 1;y++)
					{
						m++;n++;
						if(m < rows && n < columns)
						{
							temp3 += input[i][m * columns + n];
						}
					}
					tep.push_back(temp3);
					m = j;
					n = k;
					temp3 = "";
					temp3 += input[i][j * columns + k];
					for(int z = 0;z < len - 1;z++)
					{
						n++;
						if(m < rows && n < columns)
						{
							temp3 += input[i][m * columns + n];
						}
					}
					tep.push_back(temp3);
					for(int p = 0;p < tep.size();p++)
					{
						if(tep[p] == test)
							count++;
					}
				}
			}
		}
		result.push_back(count);
	}
	for(int t = 0;t < result.size();t++)
	{
		cout << result[t] << endl;
	}
}

int main()
{
	searchWord();
	return 0;
}
