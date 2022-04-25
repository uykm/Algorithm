// https://www.acmicpc.net/problem/1935
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

double operate(double& _num1, char _op, double& _num2);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string input;
	cin >> N >> input;


	vector<int> temp(N);
	// vector<int> temp; - case 2
	stack<double> result;

	for (int i = 0; i < N; i++)
	{
		cin >> temp[i];   // 벡터의 크기를 정하지 않은 상태에서 이렇게 처리하면 Debug error!
		// int num;		
		// cin >> num;
		// temp.push_back(num);
	}

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			result.push(temp[input[i] - 'A']);
		}
		else
		{
			if (!result.empty())
			{
				double num1 = result.top();
				result.pop();
				double num2 = result.top();
				result.pop();
				char op = input[i];

				double resultNum = 0;
				resultNum = operate(num1, op, num2);
				result.push(resultNum);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << result.top();

	return 0;
}

double operate(double& _num1, char _op, double& _num2)
{
	if (_op == '+')
	{
		return (_num2 + _num1);
	}
	else if (_op == '-')
	{
		return (_num2 - _num1);
	}
	else if (_op == '*')
	{
		return (_num2 * _num1);
	}
	else if (_op == '/')
	{
		return (_num2 / _num1);
	}
}