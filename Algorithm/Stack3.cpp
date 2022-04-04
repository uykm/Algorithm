#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	stack<char> st;

	int T;
	cin >> T;
	cin.ignore();		// getline ���� �Է¹�������, cin ��� �� '\n'�� �Է¹��ۿ� �����־� �̷��� ���۸� ����־�� ��.
						// getline �� cin ó�� ���͸� �������� �ʰ� �ϳ��� �Է����� �޾Ƶ��̱� ������.
	for (int i = 0; i < T; i++)
	{
		string arr;
		getline(cin, arr);		// getline() �� string ���� ���� ��� ���, ������ ���Ե� ���ڿ��� �Է¹ޱ� ������.
								// getline(�Է� ��Ʈ��, string ��ü, ������(������ ���, '\n'�� �ν�)
								// cin.getline() �� char* �� ���ڿ��� �޴� ��쿡 ���
		arr += ' ';		// ������ �� ' ' �� ��ȯ

		for (auto key : arr)	// arr �� ��Ҹ� �ݺ��Ͽ� ���� key�� �Ҵ��ϴ� ��
								// �̶�, key �� �迭 arr �� ���� �ڷ����̾�� �ϱ� ������, auto Ű���带 Ȱ��
		{
			if (key == ' ')		// ������ �߰��̳� ���� ���
			{
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}
				cout << key;		// ���� ���
			}
			else 
				st.push(key);
		}
		cout << '\n';
	}
	return 0;
}