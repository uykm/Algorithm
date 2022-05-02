// https://www.acmicpc.net/problem/1934
#include <iostream>
#include <vector>
using namespace std;

int GCD(int, int);
double LCM(int, int);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	vector<int> result(T);

	for(int i = 0; i < T; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		result[i] = LCM(num1, num2);
		// ������ ũ��(N)�� �����ϰ� push_back �� ����ϴ� �Ǽ� ����
		// result.push_back(LCM(num1, num2));
	}

	for (auto iter : result)
	{
		cout << iter << '\n';
	}

	return 0;
}

int GCD(int num1, int num2)
{
	int big, small;
	if (num1 >= num2)
	{
		big = num1;
		small = num2;
	}
	else
	{
		big = num2;
		small = num1;
	}

	int remainder = big % small;
	while (remainder != 0)
	{
		big = small;
		small = remainder;
		remainder = big % small;
	}

	return small;
}

double LCM(int num1, int num2)
{
	return num1 * num2 / GCD(num1, num2);
}