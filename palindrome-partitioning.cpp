/*

Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]


*/

public class Solution {
   public List<List<String>> partition(String s) {
        List<List<String>> ret = new ArrayList<List<String>>();
        if (s == null) {
            return ret;
        }
        
        dfs(s, 0, new ArrayList<String>(), ret);
        return ret;
    }
    
    public static void dfs(String s, int index, List<String> path, List<List<String>> ret) {
        int len = s.length();
        if (index == len) {
            ret.add(new ArrayList<String>(path));
            return;
        }
        
        for (int i = index; i < len; i++) {
            String sub = s.substring(index, i + 1);
            if (!isPalindrome(sub)) {
                continue;
            }
            
            path.add(sub);
            dfs(s, i + 1, path, ret);
            path.remove(path.size() - 1);
        }
    }
    
    public static boolean isPalindrome(String s) {
        int len = s.length();
        int left = 0;
        int right = len - 1;
        
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};