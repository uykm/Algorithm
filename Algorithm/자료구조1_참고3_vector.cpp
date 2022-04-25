// https://www.acmicpc.net/problem/10808
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> cnt(26, 0);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		cnt[input[i] - 'a'] += 1;
	}

	for (int iter : cnt)
	{
		cout << iter << ' ';
	}

	return 0;
}
