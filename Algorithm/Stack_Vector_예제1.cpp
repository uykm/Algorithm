// Stack - 수열을 만들 수 있는지 확인하기 위해 활용되는 자료구조
// Vector - 수열을 만들 수 있을 때 필요한 연산들을 저장하는 자료구조
/*
	Vector STL
	vector 선언 => vector<변수 타입> 이름;
				=> vector<변수 타입> 이름(크기, 초기화 상수);
	
	vector<int> v;
	원소 접근
	v[idx] : 벡터 v의 idx번째의 원소 참조
	v.at(idx) : 벡터 v의 idx번째 원소 참조
	v.front() : 벡터 v의 첫번째 원소 참조
	v.back() : 벡터 v의 첫번째 원소 참조
	v.begin() : iterator로 접근 시 벡터 v의 맨 첫 번째 데이터 위치를 가리킴.
	v.end() : iterator로 접근 시 벡터 v의 맨 마지막 데이터 위치의 다음을 가리킴.

	삽입/삭제 함수
	v.push_back(데이터); : 벡터 v의 데이터 타입에 맞는 데이터(정수, 문자열, 문자 등등) 를 맨 끝에 삽입
	v.pop_back();		 : 벡터 v의 맨 끝 데이터를 삭제
	v.insert(데이터 위치, 데이터) : 벡터 v의 원하는 위치(2)에 데이터(3)를 삽입하고 싶은 경우 v.insert(2,3) 으로 선언
	v.erase(iter) : 반복자인 iter을 통해 원소 위치에 접근하여 벡터 v의 데이터를 삭제

	크기(사이즈) 함수
	v.size()       : 현재 벡터 v의 원소 갯수(크기)를 리턴
	v.capacity()   : 할당된 벡터의 원소 갯수(크기)를 리턴
	v.resize(n)    : 벡터를 원래 크기에서 N 크기로 변경
	v.resize(n,10) : 벡터를 크기 N으로 변경하며 데이터를 10으로 초기화
	v.empty()	   : 벡터 v가 비어있는 지 확인. 현재 비어있는 경우 True 를 반환, 비어있지 않을 경우 False를 리턴
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> check;
vector<char> storage;

int main(void)
{
	int num = 0;
	check.push(num);
	num++;

	bool output = true;

	int n;
	cin >> n;

	while (n--)
	{
		int input;
		cin >> input;
		while (check.top() < input)		// 초반에 스택 check 에 0을 푸쉬하는 이유 : 스택에 아무 원소도 없으면 top 함수를 사용할 때 문제 발생
		{
			check.push(num);
			num++;
			storage.push_back('+');
		}
		if (check.top() == input)
		{
			check.pop();
			storage.push_back('-');
		}
		else		// 스택 수열 만드는 것이 불가능한 경우
		{
			output = false;
		}
	}

	if (!output)
	{
		cout << "NO" << "\n";
	}
	else
	{
		/*
		for (auto iter = v.begin(); iter < v.end(); iter++)
		{
			cout << *iter << '\n';
		}
		*/
		for (auto iter : storage)
		{
			cout << iter << '\n';
		}
	}
}
