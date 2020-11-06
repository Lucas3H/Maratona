#include<bits/stdc++.h>

using namespace std;

int main(){
	stack<int> s;
	queue<int> q;

	s.push(0);
	q.push(0);
	s.push(-1);
	q.push(1);
	s.push(-2);
	q.push(2);

	cout << s.top() << " " << q.front() << " " << q.back() << endl;
	
	s.pop();
	q.pop();

	cout << s.top() << " " << q.front() << " " << q.back() << endl;

	// Tem a funcao swap que é identica à do deque.

	return 0;
}
