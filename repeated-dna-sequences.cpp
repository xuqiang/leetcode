/*

Repeated DNA Sequences


All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

参考 http://www.cnblogs.com/grandyang/p/4284205.html


此题由于构成输入字符串的字符只有四种，分别是A, C, G, T，下面我们来看下它们的ASCII码用二进制来表示：

A: 0100 0001　　C: 0100 0011　　G: 0100 0111　　T: 0101 0100

由于我们的目的是利用位来区分字符，当然是越少位越好，通过观察发现，每个字符的后三位都不相同，故而我们可以用末尾三位来区分这四个字符。而题目要求是10个字符长度的串，每个字符用三位来区分，10个字符需要30位，在32位机上也OK。为了提取出后30位，我们还需要用个mask，取值为0x7ffffff，用此mask可取出后27位，再向左平移三位即可。算法的思想是，当取出第十个字符时，将其存在哈希表里，和该字符串出现频率映射，之后每向左移三位替换一个字符，查找新字符串在哈希表里出现次数，如果之前刚好出现过一次，则将当前字符串存入返回值的数组并将其出现次数加一，如果从未出现过，则将其映射到1.
*/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) return res;
        int mask = 0x7ffffff;
        unordered_map<int, int> m;
        int cur = 0, i = 0;
        while (i < 9) {
            cur = (cur << 3) | (s[i++] & 7);
        }
        while (i < s.size()) {
            cur = ((cur & mask) << 3) | (s[i++] & 7);
            if (m.find(cur) != m.end()) {
                if (m[cur] == 1) res.push_back(s.substr(i - 10, 10));
                ++m[cur]; 
            } else {
                m[cur] = 1;
            }
        }
        return res;
    }
};