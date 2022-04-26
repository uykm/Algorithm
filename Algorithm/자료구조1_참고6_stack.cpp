// https://www.acmicpc.net/problem/2743
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<char> str;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		str.push(s[i]);
	}

	cout << str.size();

	return 0;
}