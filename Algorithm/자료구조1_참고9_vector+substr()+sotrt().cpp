// https://www.acmicpc.net/problem/11656
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	/*
		NOTE. ���ڿ��� �κ� ��� �޼���(�Լ�) : substr()
		# ������� <string>
		ù ��° ������ ��ġ = pos
		�κ� ���ڿ��� ����	= len
		substr(pos, pos + len);
	*/
	for (int i = 0; i < input.length(); i++)
	{
		string str = input.substr(i, input.length());
		v.push_back(str);
	}

	/*
		NOTE. STL ���� �Լ� sort()
		# ������� <algorithm> 
		�������� => sort(������ �ּ�, ������ ���� �ּ� + 1)
		�������� => sort(������ �ּ�, ������ ���� �ּ� + 1, ������ ������ �������� ���� �Լ�)

	*/
	sort(v.begin(), v.end());

	for (auto iter : v)
	{
		cout << iter << '\n';
	}

	return 0;
}
