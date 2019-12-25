//2019年校招网易游戏笔试题
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int judgetwo(string password)
{
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	vector<char> temp;
	temp.push_back('!');
	temp.push_back('@');
	temp.push_back('#');
	temp.push_back('$');
	temp.push_back('%');
	temp.push_back('^');
	temp.push_back('&');
	temp.push_back('*');
	temp.push_back('(');
	temp.push_back(')');
	temp.push_back('_');
	temp.push_back('-');
	temp.push_back('=');
	temp.push_back('+');
	temp.push_back('[');
	temp.push_back(']');
	temp.push_back(',');
	temp.push_back('.');
	temp.push_back('<');
	temp.push_back('>');
	temp.push_back('/');
	temp.push_back('?');
	for(int i = 0;i < password.length();i++)
	{
		if(password[i] >= 65 && password[i] <= 90)
		{
			one = 1;
		}
		if(password[i] >= 97 && password[i] <= 122)
		{
			two = 1;
		}
		if(find(temp.begin(),temp.end(),password[i]) != temp.end())
		{
			three = 1;
		}
		if(password[i] >= 48 && password[i] <= 57)
		{
			four = 1;
		}
	}
	if(one == 1 && two == 1 && three == 1 && four == 1)
		return 1;
	else
		return 0;
}

int judgethree(string password)
{
	for(int i = 0;i < password.length() - 2;i++)
	{
		if((password[i] >= 48 && password[i] <= 57) && (password[i + 1] >= 48 && password[i + 1] <= 57) && (password[i + 2] >= 48 && password[i + 2] <= 57))
		{
			if((password[i + 2] - password[i + 1]) == (password[i + 1] - password[i]))
			{
				return 0;
			}
		}
	}
	return 1;
}

int judgefour(string password)
{
	for(int i = 0;i < password.length() - 2;i++)
	{
		if((password[i] >= 65 && password[i] <= 90) && (password[i + 1] >= 65 && password[i + 1] <= 90) && (password[i + 2] >= 65 && password[i + 2] <= 90))
		{
			if((password[i + 2] == password[i + 1] + 1) && (password[i + 1] == password[i] + 1))
			{
				return 0;
			}
		}
		if((password[i] >= 97 && password[i] <= 122) && (password[i + 1] >= 97 && password[i + 1] <= 122) && (password[i + 2] >= 97 && password[i + 2] <= 122))
		{
			if((password[i + 2] == password[i + 1] + 1) && (password[i + 1] == password[i] + 1))
			{
				return 0;
			}
		}
	}
	return 1;
}
int judgefive(string password)
{
	int flag = 0;
	string a = "password";
	string b = "admin";
	string c = "qwerty";
	string d = "hello";
	string e = "iloveyou";
	string f = "112233";
	if(password.find(a) != string::npos)
	{
		flag = 1;
	}
	if(password.find(b) != string::npos)
	{
		flag = 1;
	}
	if(password.find(c) != string::npos)
	{
		flag = 1;
	}
	if(password.find(d) != string::npos)
	{
		flag = 1;
	}
	if(password.find(e) != string::npos)
	{
		flag = 1;
	}
	if(password.find(f) != string::npos)
	{
		flag = 1;
	}
	if(flag == 1)
		return 0;
	else
		return 1;
}
void JudgePassWord(vector<string> & password)
{
	vector<string> result;
	for(vector<string>::iterator iter = password.begin();iter != password.end();iter++)
	{
		string passtemp = *iter;
		int flag = 0;
		if(passtemp.length() >= 8 && judgetwo(passtemp) == 1 && judgethree(passtemp) == 1 && judgefour(passtemp) == 1 && judgefive(passtemp) == 1)
		{
			flag = 1;
		}

		if(flag == 0)
		{
			result.push_back("no");
		}
		else
		{
			result.push_back("yes");
		}

	}
	for(vector<string>::iterator iter = result.begin();iter != result.end();iter++)
    {

        cout << *iter << endl;
    }
}

int main()
{
	vector<string> password;
	string inputtemp = "";
	int count = 0;
	cin >> count;
	for(int i = 0;i < count;i++)
	{
		cin >> inputtemp;
		password.push_back(inputtemp);
	}
	JudgePassWord(password);

	return 0;
}
