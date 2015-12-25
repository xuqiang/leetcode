/*

sqrt

牛顿方法

*/


#include <stack>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
  		if(x == 0) return 0;
  		double last  = 0;
  		double res = 1;
  		while( res != last ) {
  			last = res;
  			res = (res + x / res) / 2;
  		}      
  		return int(res);
    }
};

int main(int argc, char* argv[]) {

}