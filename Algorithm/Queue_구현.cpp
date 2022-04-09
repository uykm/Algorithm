/*
* 큐(Queue) : FIFO(First In First Out) 구조
* 기본 함수 : push, pop, empty, front, back, swap
queue 선언
- queue<데이터 타입> 이름;
*/

#include <iostream>
#include <string>
#define SIZE 10001
using namespace std;

template <typename T = int>		// 템플릿 인수 T에 int 를 디폴트 값으로 선언
class Queue
{
private:
	int front_index;
	int back_index;
	T* values;
public:
	Queue()
	{
		front_index = -1;
		back_index = -1;
		values = new T[SIZE];
	}
	void push(T value)
	{
		if (empty())
		{
			back_index = (back_index + 1) % SIZE;
			values[back_index] = value;
			front_index++;
		}
		else
		{
			back_index = (back_index + 1) % SIZE;
			values[back_index] = value;
		}
	}
	void pop()
	{
		if (empty())	cout << "-1" << '\n';
		else if (front_index == back_index && front_index != -1)
		{
			cout << values[front_index] << '\n';
			front_index = -1;
			back_index = -1;
		}
		else
		{
			cout << values[front_index] << '\n';
			front_index = (front_index + 1) % SIZE;
		}
	}
	T size()
	{
		int front = front_index;
		int size = 1;
		if (empty()) return 0;
		while (front != back_index)
		{
			front = (front + 1) % SIZE;
			size++;
		}
		return size;
	}
	bool empty()
	{
		return (front_index == -1) ? true : false;
	}
	T front()
	{
		if (empty())	return -1;
		return values[front_index];
	}
	T back()
	{
		if (empty())	return -1;
		return values[back_index];
	}
	~Queue()
	{
		delete[]values;
	}
};

int main(void)
{
	Queue<> q;		// 자료형 정보를 생략하면, 객체를 int 형으로 인식
	int N;
	cin >> N;

	while (N--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop")
		{
			q.pop();
		}
		else if (cmd == "size")
		{
			cout << q.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (cmd == "front")
		{
			cout << q.front() << '\n';
		}
		else if (cmd == "back")
		{
			cout << q.back() << '\n';
		}
	}
}