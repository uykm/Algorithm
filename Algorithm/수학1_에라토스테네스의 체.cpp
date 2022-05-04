// https://www.acmicpc.net/problem/1978
/*
	NOTE. �����佺�׳׽��� ü

	- �Ҽ��� ã�ų� �Ǻ��ϱ� ���� ������ �˰���
	�� �־��� �ڿ��� N�� �Ҽ��̱� ���� �ʿ� ��������� N�� N�� �����ٺ��� ũ�� ���� � �Ҽ��ε� �������� �ʴ´�.

	�� �Ҽ��� �Ǻ��� ���� �Ϲ����� ���ٹ��
	- ���� N�� 1�� N���� ����� ������ �Ҽ��̱� ������, 2���� N-1���� ���������� ���� �ִ��� �ݺ��ؼ� Ȯ��

	�� �����佺�׳׽��� ü�� �̿��� �������� ���� ����
	: 2���� N-1������ �ƴ�, 2���� N�� �����ٱ����� ���� Ȯ���ϸ� �Ǽ� ���ʿ��� �ݺ��� ���̰� ȿ�������� �Ҽ� �Ǻ� ����!
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