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
		// if (str[i] == '(') st.push(str[i]);	- ��Ÿ�ӿ��� �߻�
		// else if (str[i] == ')') st.pop();
		if (st.empty() || str[i] == '(') st.push(str[i]);
		else if (st.top() == '(') st.pop();		// str[i] == ')' �̸� st.top() == '(' �� ���
	}

	if (st.empty()) cout << "YES" << "\n";
	else
	{
		while (!st.empty()) st.pop();		// ���� �ʱ�ȸ
		cout << "NO" << "\n";
	}
}