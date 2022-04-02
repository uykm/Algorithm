#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<int>S;

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