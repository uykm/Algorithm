// https://www.acmicpc.net/problem/2609
/*
	NOTE. 유클리드 알고리즘(Euclidean algorithm)
	: 2개의 자연수의 최대공약수를 구하는 알고리즘
	두 개의 자연수 a, b가 주어짐.(단, a>b)
	a를 b로 나눈 나머지를 r이라고 했을때, GCD(a, b) = GCD(b, r) 이 성립됨
	이때, r이 0이면 그때의 b가 두 자연수 a와 b의 최대공약수임.

	# 유클리드 호제법 - GCD(a, b) = GCD(b, r)
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

// 반복문 활용
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

/*	재귀 함수 활용
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