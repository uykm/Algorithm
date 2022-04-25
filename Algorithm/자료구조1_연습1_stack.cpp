// https://www.acmicpc.net/problem/17413
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;
bool tagClose = true;

string stackPrint()
{
	string s;
	while (!st.empty())
	{
		s += st.top();
		st.pop();		// ���� �ʱ�ȭ
	}
	return s;			// ���� �ڷḦ ������ ���ڿ� s ��ȯ
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	getline(cin, input, '\n');
	input += ' ';

	for (const auto& key : input)
	{
		if (key == '<')
		{
			cout << stackPrint();		
			// �� �ڵ尡 ������, ' '�� '<' ������ ���ڿ��� �ٷ� ��µ��� �ʰ�,
			// tagClose == true �϶� ��µǰ� ��.
			cout << key;
			tagClose = false;
		}
		else if (key == '>')
		{
			cout << key;
			tagClose = true;
		}
		else if(tagClose == true)
		{
			if(key == ' ')	cout <<	stackPrint() << ' ';
			else
			{
				st.push(key);
			}
		}
		else if (tagClose == false)
		{
			cout << key;
		}
	}
}