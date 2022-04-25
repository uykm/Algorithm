// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

stack<char> op;			// 연산자 스택
vector<char> postfix;	// 후위 표기식

void ToPostfix(string);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string infix;
	cin >> infix;

	ToPostfix(infix);

	return 0;
}

void ToPostfix(string _infix)
{
	for (int i = 0; i < _infix.length(); i++)
	{
		if (_infix[i] >= 'A' && _infix[i] <= 'Z')
		{
			postfix.push_back(_infix[i]);
		}
		else
		{
			if (_infix[i] == '(')
			{
				op.push(_infix[i]);
			}
			else if (_infix[i] == ')')
			{
				while (op.top() != '(')
				{
					// 참조형 매개변수 _postfix 의 자료형이 string 인 경우
					// _postfix += op.top();
					postfix.push_back(op.top());
					op.pop();
				}
				op.pop();	// 스택 op 에서 '(' pop 
			}
			else if (_infix[i] == '*' || _infix[i] == '/')
			{
				// op.top 이 '*' 나 '/' 인 경우
				while (!op.empty() && (op.top() == '*' || op.top() == '/'))
				{
					postfix.push_back(op.top());
					op.pop();
				}
				// 스택 op가 비어있는 경우
				op.push(_infix[i]);
			}
			else if (_infix[i] == '+' || _infix[i] == '-')
			{
				// op.top 이 '*' 나 '-'인 경우
				while (!op.empty() && op.top() != '(')
				{
					postfix.push_back(op.top());
					op.pop();
				}
				// op.top 이 '('이거나 스택 op가 비어있는 경우
				op.push(_infix[i]);
			}
		}
	}
	while (!op.empty())		// 스택 op 에 남아있는 연산자들을 벡터 postfix 에 push_back
	{
		postfix.push_back(op.top());
		op.pop();
	}

	for (int i = 0; i < postfix.size(); i++)
		cout << postfix[i];
}