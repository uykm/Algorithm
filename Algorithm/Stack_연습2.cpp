// https://www.acmicpc.net/problem/10799
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> stick;
	int total = 0;
	string input;
	cin >> input;
	for (int i = 0; i <= input.length(); i++)
	{
		if (input[i] == '(')
		{
			stick.push(input[i]);
		}
		else if(input[i] == ')' && input[i-1] == '(')
		{ 
			stick.pop();
			total += stick.size();
		}
		else if (input[i] == ')')
		{
			stick.pop();
			total += 1;
		}
	}

	cout << total;

	return 0;
}