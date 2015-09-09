/*
 * 使用stack 模拟queue
 */ 
#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
	void push(int x) {
		while(_s2.empty() == false){
			_s1.push( _s2.top() );
			_s2.pop();
		}
		_s1.push(x);
	}
	
	void pop() {
		if( _s2.empty() == false ){
			_s2.pop();	
		} else {
			while(_s1.empty() == false) {
				_s2.push( _s1.top() );
				_s1.pop();
			}	
			_s2.pop();
		}
	}

	int peek() {
		int ret;
		if( _s2.empty() == false ){
			ret = _s2.top();	
		} else {
			while(_s1.empty() == false) {
				_s2.push( _s1.top() );
				_s1.pop();
			}	
			ret = _s2.top();
		}
		return ret;
	}

	bool empty() {
		return _s1.empty() && _s2.empty();	
	}
	stack<int> _s1;
	stack<int> _s2;
};



int main() {
	Queue q;
	q.push(1);
	q.push(2);		// 2 1
	cout << q.peek() << endl;
	q.push(3);		// 3 2 1
	q.push(4);		// 4 3 2 1
	q.pop();		// 4 3 2
	cout << q.peek() << endl; // 2
	q.pop();		// 4 3 
	cout << q.peek() << endl; // 3
	return 0;
}
