/*
Text Justification


Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

搜索算法

*/


public class Solution {
    List<String> res = new ArrayList<String>();
    public List<String> fullJustify(String[] words, int L) {
        dfs(words, L);
        return res;
    }
    private void dfs(String words[], int l) {
        if (words.length == 0)    return;
        int currentLength = words[0].length(), spaceCount = 0;
        StringBuilder sb = new StringBuilder(words[0]);
        for (int i = 0; i < words.length; i++) {
            if (i > 0)    currentLength += words[i].length() + 1;
            if (currentLength <= l) {
                if (i == words.length - 1) {
                    spaceCount = Math.max(i, 0);
                    fillSpace(sb, words, currentLength, spaceCount, l, true);
                    return;
                } else    continue;
            } else {
                currentLength -= words[i].length() + 1;
                spaceCount = i - 1;
                fillSpace(sb, words, currentLength, spaceCount, l, false);
                String[] left = Arrays.copyOfRange(words, i, words.length);
                dfs(left, l);
                break;
            }
        }
    }
    private void fillSpace(StringBuilder sb, String[] words, int currentLength,
            int spaceCount, int l, boolean lastLine) {
        StringBuilder[] spaces = new StringBuilder[spaceCount];
        if (lastLine) {
            for (int i = 1; i < words.length; i++) {
                sb.append(' ').append(words[i]);
            }
            while (sb.length() < l)    sb.append(' ');
            res.add(sb.toString());
            return;
        }
        if (spaceCount == 0) {
            for (int i = 0; i < l - currentLength; sb.append(' '), i++);
            res.add(sb.toString());
            return;
        }
        for (int j = 0; j < spaceCount; spaces[j++] = new StringBuilder(" "));
        int index = 0;
        for (int j = 0; j < l - currentLength; j++) {
            spaces[index++ % (spaceCount)].append(' ');
        }
        for (int j = 0; j < spaceCount; j++) {
            sb.append(spaces[j]);
            if (j + 1 < words.length)
                sb.append(words[j + 1]);
        }
        res.add(sb.toString());
    }
    
}
