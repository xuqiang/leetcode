#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    int j = 1;
    for(int i = digits.size() - 1; i >= 0; i--) {
        int k = digits[i] + j;
        res.insert(res.begin(),  k % 10 );
        j = k / 10;
        cout << digits[i] << " "  << k << " " << j << " " << endl;
    }
    if(j == 1) {
        res.insert( res.begin(), j );
    }
    return res;
}

int main() {
    // 129
    vector<int> digits;
    digits.push_back( 1 );
    digits.push_back( 2 );
    digits.push_back( 9 );
    vector<int> res = plusOne(digits);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " "  ;
    cout << endl;
    return 0;
}
~
