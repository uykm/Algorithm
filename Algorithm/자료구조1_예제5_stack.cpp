// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> temp,result;

int main(void)
{
	string s;
	cin >> s;

	for (auto& iter : s)
	{
		temp.push(iter);
	}

	int m;
	cin >> m;
	while (m--)
	{
		char cmd;
		cin >> cmd;

		if (cmd == 'L')
		{
			if (!(temp.empty()))
			{
				result.push(temp.top());
				temp.pop();
			}
		}
		else if (cmd == 'D')
		{
			if (!(result.empty()))
			{
				temp.push(result.top());
				result.pop();
			}
		}
		else if (cmd == 'B')
		{
			if (!(temp.empty()))
			{
				temp.pop();
			}
		}
		else if (cmd == 'P')
		{
			char ch;
			cin >> ch;
			temp.push(ch);
		}
	}
	while(!(temp.empty()))
	{
		result.push(temp.top());
		temp.pop();
	}
	while (!(result.empty()))
	{
		cout << result.top();
		result.pop();
	}
}