#include <iostream>
#include <string>
#include <stack>
using namespace std;

void CheckFunc(string);

stack<char> st;

int main(void)
{
	int T;
	cin >> T;
	
	while (T--)
	{
		string str;
		cin >> str;
		CheckFunc(str);
	}
}

void CheckFunc(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		// if (str[i] == '(') st.push(str[i]);	- 런타임오류 발생
		// else if (str[i] == ')') st.pop();
		if (st.empty() || str[i] == '(') st.push(str[i]);
		else if (st.top() == '(') st.pop();		// str[i] == ')' 이며 st.top() == '(' 인 경우
	}

	if (st.empty()) cout << "YES" << "\n";
	else
	{
		while (!st.empty()) st.pop();		// 스택 초기회
		cout << "NO" << "\n";
	}
}