// Stack - ������ ���� �� �ִ��� Ȯ���ϱ� ���� Ȱ��Ǵ� �ڷᱸ��
// Vector - ������ ���� �� ���� �� �ʿ��� ������� �����ϴ� �ڷᱸ��
/*
	Vector STL
	vector ���� => vector<���� Ÿ��> �̸�;
				=> vector<���� Ÿ��> �̸�(ũ��, �ʱ�ȭ ���);
	
	vector<int> v;
	���� ����
	v[idx] : ���� v�� idx��°�� ���� ����
	v.at(idx) : ���� v�� idx��° ���� ����
	v.front() : ���� v�� ù��° ���� ����
	v.back() : ���� v�� ù��° ���� ����
	v.begin() : iterator�� ���� �� ���� v�� �� ù ��° ������ ��ġ�� ����Ŵ.
	v.end() : iterator�� ���� �� ���� v�� �� ������ ������ ��ġ�� ������ ����Ŵ.

	����/���� �Լ�
	v.push_back(������); : ���� v�� ������ Ÿ�Կ� �´� ������(����, ���ڿ�, ���� ���) �� �� ���� ����
	v.pop_back();		 : ���� v�� �� �� �����͸� ����
	v.insert(������ ��ġ, ������) : ���� v�� ���ϴ� ��ġ(2)�� ������(3)�� �����ϰ� ���� ��� v.insert(2,3) ���� ����
	v.erase(iter) : �ݺ����� iter�� ���� ���� ��ġ�� �����Ͽ� ���� v�� �����͸� ����

	ũ��(������) �Լ�
	v.size()       : ���� ���� v�� ���� ����(ũ��)�� ����
	v.capacity()   : �Ҵ�� ������ ���� ����(ũ��)�� ����
	v.resize(n)    : ���͸� ���� ũ�⿡�� N ũ��� ����
	v.resize(n,10) : ���͸� ũ�� N���� �����ϸ� �����͸� 10���� �ʱ�ȭ
	v.empty()	   : ���� v�� ����ִ� �� Ȯ��. ���� ����ִ� ��� True �� ��ȯ, ������� ���� ��� False�� ����
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> check;
vector<char> storage;

int main(void)
{
	int num = 0;
	check.push(num);
	num++;

	bool output = true;

	int n;
	cin >> n;

	while (n--)
	{
		int input;
		cin >> input;
		while (check.top() < input)		// �ʹݿ� ���� check �� 0�� Ǫ���ϴ� ���� : ���ÿ� �ƹ� ���ҵ� ������ top �Լ��� ����� �� ���� �߻�
		{
			check.push(num);
			num++;
			storage.push_back('+');
		}
		if (check.top() == input)
		{
			check.pop();
			storage.push_back('-');
		}
		else		// ���� ���� ����� ���� �Ұ����� ���
		{
			output = false;
		}
	}

	if (!output)
	{
		cout << "NO" << "\n";
	}
	else
	{
		/*
		for (auto iter = v.begin(); iter < v.end(); iter++)
		{
			cout << *iter << '\n';
		}
		*/
		for (auto iter : storage)
		{
			cout << iter << '\n';
		}
	}
}
