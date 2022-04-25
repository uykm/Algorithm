// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

stack<char> op;			// ������ ����
vector<char> postfix;	// ���� ǥ���

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
					// ������ �Ű����� _postfix �� �ڷ����� string �� ���
					// _postfix += op.top();
					postfix.push_back(op.top());
					op.pop();
				}
				op.pop();	// ���� op ���� '(' pop 
			}
			else if (_infix[i] == '*' || _infix[i] == '/')
			{
				// op.top �� '*' �� '/' �� ���
				while (!op.empty() && (op.top() == '*' || op.top() == '/'))
				{
					postfix.push_back(op.top());
					op.pop();
				}
				// ���� op�� ����ִ� ���
				op.push(_infix[i]);
			}
			else if (_infix[i] == '+' || _infix[i] == '-')
			{
				// op.top �� '*' �� '-'�� ���
				while (!op.empty() && op.top() != '(')
				{
					postfix.push_back(op.top());
					op.pop();
				}
				// op.top �� '('�̰ų� ���� op�� ����ִ� ���
				op.push(_infix[i]);
			}
		}
	}
	while (!op.empty())		// ���� op �� �����ִ� �����ڵ��� ���� postfix �� push_back
	{
		postfix.push_back(op.top());
		op.pop();
	}

	for (int i = 0; i < postfix.size(); i++)
		cout << postfix[i];
}