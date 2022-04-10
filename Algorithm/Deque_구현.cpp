/*
* 덱(Deque) : 양방향 큐(Doubled-Ended Queue)의 줄임말
* 기본 함수 : push_back(), pop_back(), push_front(), pop_front()
			 , insert(iterator, 원소 x), erase(iterator), empty(), size()
* 큐(Queue) 와 달리 iterator를 이용하여 중간에 데이터 삽입과 삭제가 가능!
* 또한, 개별 원소들을 Index 로 접근 가능!
* 앞/뒤의 데이터 삽입 삭제가 자주 발생할 경우에 사용!
* 삽입 / 삭제 : list > deque > vector (삽입/삭제가 느림)
* 검색 속도 : vector > deque > list (Index로 원소에 직접 접근이 불가능해서 접근이 느림)
*/
// ★ 항상 조건문을 사용할 땐, 모든 경우를 고려하여 사용하기!

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