// https://www.acmicpc.net/problem/17299
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> input;
stack<int> s;		// ����ū���� ã�� �� �׿��ִ� ����
vector<int> NGF;	// �ش� ������ ����ū���� �Ǵ� ��

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
		// s.top() �� input[i] �� ����ū���� �ƴϸ� ���ÿ��� pop
		// �� ����ū���� ���� ������ pop
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
	/* �������� ����ū�� ã�� 
	// while�� : ����ū���� ã���� ���� NGF�� �����ϰ�, ����ū���� ���� ã�� ���� ���ҵ��� �׿��ִ� "���� s" ���� ����ū���� ã�Ե� ���� pop!
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

/*	���� �ڵ� : pair Ȱ��
* pair - �� ������ �ڷḦ �ϳ��� �����̳ʿ� ������ �� �ִ� ���ø�
* ������� <utility>
* pair �� stack, vector, queue �� �پ��� �����̳ʿ� Ȱ�� �����ϸ�, vector �� ���� ����
* �������� ���� �� ������ �ڷᰡ �ϳ��� �����̳�(ex. vector)�� �� �� �ִ� ���������ε� �����ϰ� ����.

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
	// �� �ڿ� �ִ� ���ں��� Ȯ��
	for (int i = N - 1; i >= 0; i--)
	{
		// ���� ��ġ�� ���ڰ� �߻��� �󵵺��� ������ top�� �ִ� �󵵰� �۰ų� ���ٸ� pop
		while (!st.empty() && visited[arr[i]] >= st.top().first)
		{
			st.pop();
		}
		// �����ʿ� ������ �����ϴ� ���ڰ� ���ٸ� -1 �ִٸ� ������ top
		result[i] = st.empty() ? -1 : st.top().second;
		// ���ÿ��� ��� �߰������ �� {�ش� ���� �󵵼�, �ش� ����}
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