/*
Number of 1 Bits

*/


#include <vector>
#include <iostream>
#include "common.h"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamm = 0;
        while(n) {
        	if(n & 1)
        		hamm ++;
        	n = n >> 1;
        }
        return hamm;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}