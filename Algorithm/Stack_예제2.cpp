// https://www.acmicpc.net/problem/9093
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	stack<char> st;

	int T;
	cin >> T;
	cin.ignore();		// getline 으로 입력받으려면, cin 사용 후 '\n'가 입력버퍼에 남아있어 이렇게 버퍼를 비워주어야 함.
						// getline 은 cin 처럼 엔터를 무시하지 않고 하나의 입력으로 받아들이기 때문임.
	for (int i = 0; i < T; i++)
	{
		string arr;
		getline(cin, arr);		// getline() 은 string 형을 받을 경우 사용, 공백이 포함된 문자열을 입력받기 편리함.
								// getline(입력 스트림, string 객체, 구분자(생략할 경우, '\n'로 인식)
								// cin.getline() 은 char* 형 문자열을 받는 경우에 사용
		arr += ' ';		// 문장의 끝 ' ' 로 변환

		for (const auto& key : arr)	// arr 의 요소를 반복하여 변수 key에 할당하는 것
								// 이때, key 는 배열 arr 과 같은 자료형이어야 하기 때문에, auto 키워드를 활용
								// 배열을 복사하는건 비용이 많이 발생하므로
								// 성능상의 이유로 참조자를 사용하면 key는 배열에 대한 참조이므로 값이 복사되지 않아 성능이 향상됨.
								// 또한, 읽기 전용으로 사용할 경우엔 const 참조를 사용하여 성능 향상됨.
		{
			if (key == ' ')		// 문장의 중간이나 끝인 경우
			{
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}
				cout << key;		// 띄어쓰기 출력
			}
			else
				st.push(key);
		}
		cout << '\n';
	}
	return 0;
}