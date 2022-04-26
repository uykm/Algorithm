// https://www.acmicpc.net/problem/11655
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	// cin >> s (X)		
	// cin 의 >> 연산자에서는 공백문자에서 입력을 끊기 때문에, 원하는 구분자를 만날 때까지 모든 문자열을 입력받는 getline() 함수를 사용해야 함.
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			int pos = (s[i] - 'a' + 13) % 26;
			s[i] = (char)('a' + pos);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int pos = (s[i] - 'A' + 13) % 26;
			s[i] = (char)('A' + pos);
		}
		else if (s[i] == ' ')
		{
			continue;
		}
	}

	cout << s;

	return 0;
}