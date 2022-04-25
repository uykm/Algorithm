// https://www.acmicpc.net/problem/10809
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pos(26, -1);

int main(void)
{
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if(pos[input[i] - 'a'] == -1)	pos[input[i] - 'a'] += (i + 1);
	}

	for (int iter : pos)
	{
		cout << iter << ' ';
	}

	return 0;
}