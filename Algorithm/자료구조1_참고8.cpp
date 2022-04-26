// https://www.acmicpc.net/problem/10824

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> num(4);		// ���͸� ���� ����� �ʿ� X
							// ���� ���� ���� ������� �����Ͽ� ����� ���̶��, vector<long long> num(4); �� ���� !

	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}

	string str1 = to_string(num[0]) + to_string(num[1]);
	string str2 = to_string(num[2]) + to_string(num[3]);

	//	NOTE. ���� to ���ڿ�
	//	to_string() �Լ�

	/*
		NOTE. ���ڿ� to ����
		int ��	     => stoi
		float ��	 => stof
		long ��		 => stol
		long long �� => stoll
	*/
	long long num1 = stoll(str1);
	long long num2 = stoll(str2);

	cout << num1 + num2;

	return 0;
}

// +) ����
// # pow()
// - ���� �Լ��� pow �� ����Ͽ� Ǯ�� ���� ( pow(base num, ���� n) = base num�� n ���� )