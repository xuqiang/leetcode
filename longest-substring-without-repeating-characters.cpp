/*


https://leetcode.com/problems/longest-substring-without-repeating-characters/


Longest Substring Without Repeating Characters


Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

建立一个256位大小的整型数组来代替哈希表，这样做的原因是ASCII表共能表示256个字符，所以可以记录所有字符，然后我们需要定义两个变量res和left，
其中res用来记录最长无重复子串的长度，left指向该无重复子串左边的起始位置，然后我们遍历整个字符串，对于每一个遍历到的字符，
如果哈希表中该字符串对应的值为0，说明没有遇到过该字符，则此时计算最长无重复子串，i - left +１，其中ｉ是最长无重复子串最右
边的位置，left是最左边的位置，还有一种情况也需要计算最长无重复子串，就是当哈希表中的值小于left，这是由于此时出现过重复的字
符，left的位置更新了，如果又遇到了新的字符，就要重新计算最长无重复子串。最后每次都要在哈希表中将当前字符对应的值赋值为i+1


http://www.cnblogs.com/grandyang/p/4480780.html
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
};