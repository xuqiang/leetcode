/*

Implement Stack using Queues

*/

#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    // Push element x onto stack.
    void push(int x) {
        q2.push(x);
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        top();
        q2.pop();
    }

    // Get the top element.
    int top() {
        if (q2.empty()) {
            for (int i = 0; i < (int)q1.size() - 1; ++i) {
                q1.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            q1.pop();
        }
        return q2.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main(int argc, char* argv[] ) {
	
}