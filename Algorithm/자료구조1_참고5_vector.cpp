// https://www.acmicpc.net/problem/10820
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string input;

	while (getline(cin, input))		// ���ڿ��� �Է¹��������� �ݺ� (char �迭�� �޴� ��쿣 cin.getlin())
	{
		vector<int> count(4, 0);
		for(int i = 0; i < input.size(); i++)
		{
			if (input[i] >= 'a' && input[i] <= 'z')			count[0] += 1;
			else if (input[i] >= 'A' && input[i] <= 'Z')	count[1] += 1;
			else if (input[i] >= '0' && input[i] <= '9')	count[2] += 1;
			else if (input[i] == ' ')						count[3] += 1;
		}
		for (int iter : count)
		{
			cout << iter << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}