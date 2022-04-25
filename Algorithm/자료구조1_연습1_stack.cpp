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
		st.pop();		// 스택 초기화
	}
	return s;			// 스택 자료를 저장한 문자열 s 반환
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
			// 위 코드가 없으면, ' '와 '<' 사이의 문자열이 바로 출력되지 않고,
			// tagClose == true 일때 출력되게 됨.
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