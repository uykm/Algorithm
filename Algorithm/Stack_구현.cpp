/*
    Stack 특징
    1) 시스템 해킹에서 버퍼오버플로우 취약점을 이용한 공격을 할 때 스택 메모리의 영역에서 함.
    2) 인터럽트처리, 수식의 계산, 서브루틴의 복귀 번지 저장 등에 쓰임.
    3) 그래프의 깊이 우선 탐색(DFS)에서 사용
    4) 재귀적(Recursion) 함수를 호출할 때 사용
*/

// STL stack 을 직접 구현

#include <iostream>
using namespace std;

class Stack
{
private:
    int stack[10000];
    int size;
public:
    Stack()
    {
        size = 0;
    }

    void push(int num)
    {
        stack[size] = num;
        size += 1;
    }
    int Size()
    {
        return size;
    }
    bool empty()
    {
        if (size == 0) return true;

        else return false;
    }
    void pop()
    {
        if (empty())
        {
            cout << -1 << '\n';
        }

        else
        {
            cout << stack[size - 1] << '\n';
            stack[size - 1] = 0;
            size -= 1;
        }
    }
    int top()
    {
        if (empty()) return -1;

        else return stack[size - 1];
    }
};

int main(void)
{
    string command;
    Stack s;

    int commandNum;
    cin >> commandNum;
    for (int i = 0; i < commandNum; i++)
    {
        cin >> command;
        if (command == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (command == "pop")
        {
            s.pop();
        }
        else if (command == "top")
        {
            cout << s.top() << '\n';
        }
        else if (command == "empty")
        {
            cout << s.empty() << '\n';
        }
        else if (command == "size")
        {
            cout << s.Size() << '\n';
        }
    }

    return 0;
}