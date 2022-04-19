#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int size;
	cin >> size;

	vector<int> arr(size+1);
	stack<int> s;
	vector<int> NGE(size+1, -1);		// 문제에서 NGE(1)부터 출력하게 했기 때문에, 인데스가 0인 경우는 제외함.

	for (int i = 1; i <= size; i++)
	{
		cin >> arr[i];
	}

	for(int i = 1; i <= size; i++)
	{
		while (!s.empty() && arr[s.top()] < arr[i])
		{
			NGE[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 1; i <= size; i++)
	{
		cout << NGE[i] << ' ';
	}

	return 0;
}