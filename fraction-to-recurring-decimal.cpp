/*

Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".



维护一个unordered_map<long, long>dict，对应关系是余数及其在res中的位置。每次计算小数点后的每一位结果时，查找是否已经在dict中，如果已经在了，那么说明已经找到了重复的部分（如结果0.(012)，目前得到res=“0.012”，结果又一次得到了0，所以小数点后第一个0开始的部分012就是循环部分），于是在res中insert括号即可return res。

*/


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string res = "";
        if(numerator < 0 ^ denominator < 0) res += "-";
        long m = abs(long(numerator));
        long n = abs(long(denominator));
        long s = m / n;
        res += to_string(s);
    
        long remain = m % n;
        if(!remain) return res;
        res += ".";
    
        unordered_map<long, long> dict;
    
        while(remain){
            if(dict.find(remain) != dict.end()){
                res.insert(dict[remain],"(");
                res += ")";
                return res;
            }
            dict[remain] = res.length();
            remain *= 10;
            s = remain / n;
            res += to_string(s);
            remain = remain % n;
        }
        return res;
    }
};