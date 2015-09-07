#include <string>
#include <iostream>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int m[26] = { 0 };
    for(int i = 0; i < s.size(); ++i) m[ s[i]- 'a' ] ++;
    for(int i = 0; i < t.size(); ++i) {
                if( --m[ t[i] - 'a' ] < 0 ) return false;
            }
    return true;
}

int main() {
    string s = "abca";
    string t = "aabc";
    cout << isAnagram(s, t) << endl;
    return 0;
}
