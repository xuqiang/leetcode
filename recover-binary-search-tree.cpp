/*


Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

*/

public class Solution {
    TreeNode pre;
    TreeNode first;
    TreeNode second;
      
    public void inorder(TreeNode root) {  
        if(root == null)  
            return;  

        inorder(root.left);  
        if(pre == null) {  
            pre = root;  //pre指针初始
        }else{  
            if(pre.val > root.val) {  
                if(first == null) {  
                    first = pre;//第一个逆序点
                }  
                second = root;  //不断寻找最后一个逆序点
            }  
            pre = root;  //pre指针每次后移一位
        }  
        inorder(root.right);  
    }  
      
    public void recoverTree(TreeNode root) {  
        pre = null;  
        first = null;  
        second = null;  
        inorder(root);  
        if(first!=null && second!=null){   
            int tmp = first.val;  
            first.val = second.val;  
            second.val = tmp;  
        }  
    }
};