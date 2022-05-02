// https://www.acmicpc.net/problem/2609
/*
	NOTE. ��Ŭ���� �˰���(Euclidean algorithm)
	: 2���� �ڿ����� �ִ������� ���ϴ� �˰���
	�� ���� �ڿ��� a, b�� �־���.(��, a>b)
	a�� b�� ���� �������� r�̶�� ������, GCD(a, b) = GCD(b, r) �� ������
	�̶�, r�� 0�̸� �׶��� b�� �� �ڿ��� a�� b�� �ִ�������.

	# ��Ŭ���� ȣ���� - GCD(a, b) = GCD(b, r)
*/
#include <iostream>
using namespace std;

int GCD(int, int);
int LCM(int, int);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num1, num2;
	cin >> num1 >> num2;
	int mul = num1 * num2;
	if (num1 >= num2)
	{
		cout << GCD(num1, num2) << '\n';
		cout << LCM(num1, num2);
	}
	else
	{
		cout << GCD(num2, num1) << '\n';
		cout << LCM(num2, num1);
	}
}

// �ݺ��� Ȱ��
int GCD(int bigNum, int smallNum)
{
	int remainder = bigNum % smallNum;
	while (remainder != 0)
	{
		bigNum = smallNum;
		smallNum = remainder;
		remainder = bigNum % smallNum;
	}

	return smallNum;
}

/*	��� �Լ� Ȱ��
int GCF(int bigNum, int smallNum)
{
	if(bigNum % smallNum == 0)
	{
		return smallNum;
	}
	else
	{
		return GCF(smallNum, bigNum % smallNum);
	}
}
*/

int LCM(int bigNum, int smallNum)
{
	return (bigNum * smallNum) / GCD(bigNum, smallNum);
}