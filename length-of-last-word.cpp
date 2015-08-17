/*
 * accepted 2015-08-17
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int lengthOfLastWord(string s) {
    stringstream ss(s);
    string tmp;
    while( ss >> tmp );
    return tmp.size();
}
int main() {
    string s = "hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
