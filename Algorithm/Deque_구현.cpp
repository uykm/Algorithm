/*
* ��(Deque) : ����� ť(Doubled-Ended Queue)�� ���Ӹ�
* �⺻ �Լ� : push_back(), pop_back(), push_front(), pop_front()
			 , insert(iterator, ���� x), erase(iterator), empty(), size()
* ť(Queue) �� �޸� iterator�� �̿��Ͽ� �߰��� ������ ���԰� ������ ����!
* ����, ���� ���ҵ��� Index �� ���� ����!
* ��/���� ������ ���� ������ ���� �߻��� ��쿡 ���!
* ���� / ���� : list > deque > vector (����/������ ����)
* �˻� �ӵ� : vector > deque > list (Index�� ���ҿ� ���� ������ �Ұ����ؼ� ������ ����)
*/
// �� �׻� ���ǹ��� ����� ��, ��� ��츦 ����Ͽ� ����ϱ�!

#include <iostream>
#include <string>
#define maxSize 10001
using namespace std;

class Deque
{
private:
	int dataSize;
	int* deque;
public:
	Deque()
	{
		dataSize = 0;
		deque = new int[maxSize];
	}

	void push_front(const int data)
	{
		if (empty())
		{
			deque[0] = data;
			dataSize++;
		}
		else
		{
			for (int i = dataSize - 1; i >= 0; i--)
			{
				deque[i + 1] = deque[i];
			}
			deque[0] = data;
			dataSize++;
		}
	}
	void push_back(const int data)
	{
		if (empty())
		{
			deque[0] = data;
			dataSize++;
		}
		else
		{
			deque[dataSize] = data;
			dataSize++;
		}
	}
	void pop_front()
	{
		cout << deque[0] << '\n';
		if (dataSize == 1)
		{
			deque[0] = 0;
			dataSize = 0;
		}
		else
		{
			for (int i = 0; i < dataSize; i++)
			{
				int tmp = deque[i + 1];
				deque[i] = tmp;
			}
			dataSize--;
		}
	}
	void pop_back()
	{
		cout << deque[dataSize-1] << '\n';
		dataSize--;
		if (empty())		deque[0] = 0;
	}
	int size()
	{
		return dataSize;
	}
	int empty()
	{
		return dataSize == 0;
	}
	int front()
	{
		if (empty()) return -1;
		return deque[0];
	}
	int back()
	{
		if (empty()) return -1;
		return deque[dataSize - 1];
	}
	~Deque()
	{
		delete[]deque;
	}
};

int main(void)
{
	Deque dq;
	int n;
	cin >> n;
	
	while (n--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push_front")
		{
			int n;
			cin >> n;
			dq.push_front(n);
		}
		else if (cmd == "push_back")
		{
			int n;
			cin >> n;
			dq.push_back(n);
		}
		else if (cmd == "pop_front")
		{
			if (dq.empty()) cout << "-1" << '\n';
			else if (!dq.empty())	dq.pop_front();
		}
		else if (cmd == "pop_back")
		{
			if (dq.empty()) cout << "-1" << '\n';
			else if (!dq.empty())	dq.pop_back();
		}
		else if (cmd == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << dq.empty() << '\n';
		}
		else if (cmd == "front")
		{
			cout << dq.front() << '\n';
		}
		else if (cmd == "back")
		{
			cout << dq.back() << '\n';
		}
	}
}