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
            cout << stack[size-1] << '\n';
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
}