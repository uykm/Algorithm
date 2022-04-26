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
	// cin �� >> �����ڿ����� ���鹮�ڿ��� �Է��� ���� ������, ���ϴ� �����ڸ� ���� ������ ��� ���ڿ��� �Է¹޴� getline() �Լ��� ����ؾ� ��.
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