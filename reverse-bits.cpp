/*

Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).

*/

#include <stack>
#include <iostream>
#include <string>
#include "common.h"

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t value = 0;
        uint32_t mask = 1;
        for (uint32_t i = 0; i < 32; ++i) {
            value = (value << 1 ) | ((n & mask) >> i);
            mask <<=1;
        }
        return value;
    }
};

int main(int argc, char* argv[]) {

}