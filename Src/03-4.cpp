/* ���� ������ Undo Redo */
#include <iostream>
#include <deque>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	/* Faster */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/* Init */
	deque<char> u;	// Undo Deque
	stack<char> r;	// Redo Stack
	string str;		// Input

	/* Input */
	getline(cin, str);

	/* Calculation */
	for (int i = 0; i < str.size(); i++) {
		/* Ignore Blank */
		if (str[i] == ' ')
			continue;
		/* U : Undo */
		else if (str[i] == 'U') {
			/* Undo Deque�� ������� ��� */
			if (u.empty()) {
				cout << "ERROR" << '\n';
				return 0;
			}
			/* ���� */
			r.push(u.front());
			u.pop_front();
		}
		/* R : Redo */
		else if (str[i] == 'R') {
			/* Redo Stack�� ������� ��� */
			if (r.empty()) {
				cout << "ERROR" << '\n';
				return 0;
			}
			/* ���� */
			u.push_front(r.top());
			r.pop();
		}
		/* a ~ z */
		else if ('a' <= str[i] && str[i] <= 'z') {
			/* ���ο� �Է��� ������ Redo Stack�� ��� */
			while (!r.empty())
				r.pop();
			/* Size�� 10���� Ŀ�� ��� */
			if (u.size() == 10)
				u.pop_back();
			/* ���� */
			u.push_front(str[i]);
		}
	}

	/* Output */
	// Undo Deque
	if (u.size() == 0)
		cout << "EMPTY";
	else
		while (u.size() != 0) {
			cout << u.front() << ' ';
			u.pop_front();
		}

	cout << '\n';

	// Redo Stack
	if (r.empty())
		cout << "EMPTY";
	else
		while (!r.empty()) {
			cout << r.top() << ' ';
			r.pop();
		}

	/* Return */
	return 0;
}