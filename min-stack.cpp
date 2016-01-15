/*
min stack

最小栈


*/

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class MinStack {
public:
    void push(int x) {
       elements.push(x);
       if (mins.empty() || x <= mins.top()) {
       	mins.push(x);
       }
    }

    void pop() {
        if (elements.empty()) return;
        // 维护最小堆 性质
        if (elements.top() == mins.top())
        	mins.pop();
        elements.pop();
    }

    int top() {
        return elements.top();
    }

    int getMin() {
        return mins.top();
    }
private:
	stack<int> elements;
	stack<int> mins;
};

int main( int argc, char* argv[] ) {
	return 0;
}

