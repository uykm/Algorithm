// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(void)
{
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	
	cout << "<";

	int tmp;
	
	while (q.size() > 1)
	{
		for (int i = 0; i < K - 1; i++)
		{
			tmp = q.front();
			q.pop();
			q.push(tmp);
		}

		tmp = q.front();
		cout << tmp << ", ";
		q.pop();
	}

	tmp = q.front();
	cout << tmp <<">\n";

	return 0;
}