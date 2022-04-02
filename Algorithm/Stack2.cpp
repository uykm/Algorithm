/*
    Stack 특징
    1) 시스템 해킹에서 버퍼오버플로우 취약점을 이용한 공격을 할 때 스택 메모리의 영역에서 함.
    2) 인터럽트처리, 수식의 계산, 서브루틴의 복귀 번지 저장 등에 쓰임.
    3) 그래프의 깊이 우선 탐색(DFS)에서 사용
    4) 재귀적(Recursion) 함수를 호출할 때 사용
*/

// STL Stack 사용
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<int> S;    // int형 스택 선언

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        string command;
        cin >> command;
        if (command == "push") 
        {
            int x; 
            cin >> x;
            S.push(x);
        }
        else if (command == "top") 
        {
            if (S.empty()) cout << "-1" << "\n";

            else cout << S.top() << "\n";
        }
        else if (command == "pop") 
        {
            if (S.empty()) cout << "-1" << "\n";

            else 
            {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if (command == "empty") 
        {
            cout << S.empty() << "\n";
        }
        else 
        {
            cout << S.size() << "\n";
        }
    }
    return 0;
}