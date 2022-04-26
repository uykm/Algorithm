// https://www.acmicpc.net/problem/11656
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	/*
		NOTE. 문자열의 부분 출력 메서드(함수) : substr()
		# 헤더파일 <string>
		첫 번째 문자의 위치 = pos
		부분 문자열의 길이	= len
		substr(pos, pos + len);
	*/
	for (int i = 0; i < input.length(); i++)
	{
		string str = input.substr(i, input.length());
		v.push_back(str);
	}

	/*
		NOTE. STL 정렬 함수 sort()
		# 헤더파일 <algorithm> 
		오름차순 => sort(시작점 주소, 마지막 지점 주소 + 1)
		내림차순 => sort(시작점 주소, 마지막 지점 주소 + 1, 사전에 정의한 내림차순 정렬 함수)

	*/
	sort(v.begin(), v.end());

	for (auto iter : v)
	{
		cout << iter << '\n';
	}

	return 0;
}
