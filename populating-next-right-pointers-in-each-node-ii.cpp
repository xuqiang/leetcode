/*

Populating Next Right Pointers in Each Node II


Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
Subscribe to see which companies asked this question

*/

// java 代码 

public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null)
            return;
        Queue<TreeLinkNode> queue = new LinkedList<TreeLinkNode>();
        queue.add(root);
        queue.add(null);

        while (!queue.isEmpty()) {
            TreeLinkNode out = queue.remove();
            if (out != null) {
                out.next = queue.peek();
                if (out.left != null)
                    queue.add(out.left);
                if (out.right != null)
                    queue.add(out.right);
            } else {
                if (!queue.isEmpty()) {
                    queue.add(null);
                }

            }

        }

    }
}