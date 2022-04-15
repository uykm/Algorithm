// https://www.acmicpc.net/problem/10866
/*
* 덱(Deque) : 양방향 큐(Doubled-Ended Queue)의 줄임말

*/
#include <iostream>
#include <string>
using namespace std;

class Deque
{
private:
	int frontIndex;
	int backIndex;
	int dataSize;
	int maxSize;
	int* deque;
public:
	Deque(const int size = 10001)
	{
		frontIndex = 0;
		backIndex = 1;
		dataSize = 0;
		maxSize = size;
		deque = new int[size];
	}

	void push_front(const int data)
	{
		deque[frontIndex] = data;
		frontIndex = ((frontIndex - 1) + maxSize) % maxSize;
		dataSize++;
	}
	void push_back(const int data)
	{
		deque[backIndex] = data;
		backIndex = ((backIndex - 1) + maxSize) % maxSize;
		dataSize++;
	}
	void pop_front()
	{
		int frontData = front();
		frontIndex = (frontIndex + 1) % maxSize;
		dataSize--;
	}
	void pop_back()
	{
		int backData = back();
		backIndex = (backIndex + 1) % maxSize;
		dataSize--;
	}
	int size()
	{
		if (dataSize < 0)	dataSize = 0;
		return dataSize;
	}
	int empty()
	{
		if (dataSize < 0)	dataSize = 0;
		return dataSize == 0;
	}
	int front()
	{
		if (empty()) return -1;
		int tempIndex = (frontIndex + 1) % maxSize;
		return deque[tempIndex];
	}
	int back()
	{
		if (empty()) return -1;
		int tempIndex = ((backIndex-1) + maxSize) % maxSize;
		return deque[tempIndex];
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
			dq.push_front(n);
		}
		else if (cmd == "pop_front")
		{
			if (dq.empty()) cout << "-1" << '\n';
			dq.pop_front();
		}
		else if (cmd == "pop_back")
		{
			if (dq.empty()) cout << "-1" << '\n';
			dq.pop_back();
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