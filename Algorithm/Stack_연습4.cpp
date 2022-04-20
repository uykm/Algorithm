// https://www.acmicpc.net/problem/17299
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> input;
stack<int> s;		// 오등큰수를 찾기 전 쌓여있는 스택
vector<int> NGF;	// 해당 원소의 오등큰수가 되는 수

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	input.resize(N + 1);
	NGF.resize(N + 1, 0);
	vector<int> count(1000001, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];
		count[input[i]]++;
	}

	for (int i = N; i >= 1; i--)
	{
		// s.top() 이 input[i] 의 오등큰수가 아니면 스택에서 pop
		// 즉 오등큰수가 나올 때까지 pop
		while (!s.empty() && count[input[i]] >= count[input[s.top()]])
		{
			s.pop();
		}
		if (s.empty())	NGF[i] = -1;
		else
		{
			NGF[i] = input[s.top()];
		}
		s.push(i);
	}
	/* 정순으로 오등큰수 찾기 
	// while문 : 오등큰수를 찾으면 스택 NGF에 저장하고, 오등큰수를 아직 찾기 못한 원소들이 쌓여있는 "스택 s" 에서 오등큰수를 찾게된 수는 pop!
	for (int i = 1; i <= N; i++)
	{
		while (!s.empty() && count[input[s.top()]]< count[input[i]])
		{
			NGF[s.top()] = input[i];
			s.pop();
		}

		s.push(i);
	}
	*/

	for (int i = 1; i <= N; i++)
	{
		cout << NGF[i] << ' ';
	}
	
	return 0;
}

/*	참고 코드 : pair 활용
* pair - 두 종류의 자료를 하나의 컨테이너에 저장할 수 있는 템플릿
* 헤더파일 <utility>
* pair 는 stack, vector, queue 등 다양한 컨테이너와 활용 가능하며, vector 와 자주 쓰임
* 연관성을 갖는 두 종류의 자료가 하나의 컨테이너(ex. vector)에 들어갈 수 있는 장점만으로도 유용하게 쓰임.

#include <iostream>
#include <stack>
using namespace std;
const int MAX = 1e6 + 10;

int arr[MAX];
int visited[MAX];
int result[MAX];
stack<pair<int, int>> st;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		visited[arr[i]]++;
	}
	// 맨 뒤에 있는 숫자부터 확인
	for (int i = N - 1; i >= 0; i--)
	{
		// 현재 위치한 숫자가 발생한 빈도보다 스택의 top에 있는 빈도가 작거나 같다면 pop
		while (!st.empty() && visited[arr[i]] >= st.top().first)
		{
			st.pop();
		}
		// 오른쪽에 조건을 만족하는 숫자가 없다면 -1 있다면 스택의 top
		result[i] = st.empty() ? -1 : st.top().second;
		// 스택에는 계속 추가해줘야 함 {해당 숫자 빈도수, 해당 숫자}
		st.push({ visited[arr[i]], arr[i] });
	}
	for (int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}
*/