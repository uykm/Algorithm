// https://www.acmicpc.net/problem/1978
/*
	NOTE. 에라토스테네스의 체

	- 소수를 찾거나 판별하기 위한 최적의 알고리즘
	▷ 주어진 자연수 N이 소수이기 위한 필요 충분조건은 N이 N의 제곱근보다 크지 않은 어떤 소수로도 나눠지지 않는다.

	＃ 소수를 판별할 때의 일반적인 접근방법
	- 숫자 N은 1과 N만을 약수로 가져야 소수이기 때문에, 2부터 N-1까지 나누어지는 수가 있는지 반복해서 확인

	→ 에라토스테네스의 체를 이용해 접근했을 떄의 장점
	: 2부터 N-1까지가 아닌, 2부터 N의 제곱근까지의 수만 확인하면 되서 불필요한 반복을 줄이고 효율적으로 소수 판별 가능!
*/

#include <iostream>
#include <cmath>
using namespace std;

void Eratosthenes(int, int&);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int count = N;
	int input[100] = { };

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		if (input[i] == 1)
		{
			count--;
		}
	}

	for (int i = 0; i < N; i++)
	{
		Eratosthenes(input[i], count);
	}

	cout << count;

	return 0;
}

void Eratosthenes(int checkNum, int& count)
{
	for (int i = 2; i <= sqrt(checkNum); i++)
	{
		if (checkNum % i == 0)
		{
			count--;
			break;
		}
	}
}