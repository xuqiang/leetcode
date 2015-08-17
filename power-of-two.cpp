#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
bool isPowerOfTwo(int n) {
    if(n < 0) return false;
    if(n == 1) return true;
    int i = 1;
    while( i <= n) {
        i = i << 2;
        if(i == n)
            return true;
    }
    return false;
}
int main() {
    string s = "hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
~
