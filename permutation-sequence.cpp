/*

Permutation Sequence

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

*/


public class Solution {
    public String getPermutation(int n, int k) {
     int[] num = new int [n];
     
     // count = !n
     int count = 1;
     for(int i = 0; i < n; i++){
         num[i] = i+1;
          count *= (i+1);
        }
     // n是从1开始 所以kth个 的下标为 k-1    
     k--;
     StringBuilder sb = new StringBuilder();
     for(int i = 0; i < n; i++) {
        //  第i层 每个节点下有多少种排列组合，注意 count是数组的下标,数组下标从 0 开始
        count /= n-i;
        // 应该选第 i层的第几个，注意 selected 是数组的下标,数组下标从 0 开始
        int selected = k / count;
        // 剪掉 第i层前面的， 得到新k
        k = k % count;
         
        sb.append(num[selected]);
         
        //restruct nums since one num has been picked  
         for(int j = selected+1; j<n; j++){
             num[j-1] = num[j];
         }
     }
     
     return sb.toString();
    }
    
    
}