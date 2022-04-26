// https://www.acmicpc.net/problem/10824

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> num(4);		// 벡터를 굳이 사용할 필요 X
							// 벡터 내에 값에 결과값을 저장하여 출력할 것이라면, vector<long long> num(4); 로 변경 !

	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}

	string str1 = to_string(num[0]) + to_string(num[1]);
	string str2 = to_string(num[2]) + to_string(num[3]);

	//	NOTE. 숫자 to 문자열
	//	to_string() 함수

	/*
		NOTE. 문자열 to 숫자
		int 형	     => stoi
		float 형	 => stof
		long 형		 => stol
		long long 형 => stoll
	*/
	long long num1 = stoll(str1);
	long long num2 = stoll(str2);

	cout << num1 + num2;

	return 0;
}

// +) 참고
// # pow()
// - 제곱 함수인 pow 를 사용하여 풀이 가능 ( pow(base num, 제곱 n) = base num의 n 제곱 )