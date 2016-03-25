/*

Simplify Path


Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".


我需要两个栈来解决问题。

先将字符串依"/"分割出来，然后检查每个分割出来的字符串。

当字符串为空或者为"."，不做任何操作。

当字符串不为".."，则将字符串入栈。

当字符串为"..", 则弹栈（返回上级目录）。



*/

// java代码

public class Solution {
    public String simplifyPath(String path) {
        if(path == null||path.length()==0)
            return path;
        
        Stack<String> stack = new Stack<String>();
        String[] list = path.split("/");
        
        for(int i=0; i<list.length; i++){
            if(list[i].equals(".")||list[i].length()==0)
                continue;
            else if(!list[i].equals(".."))
                stack.push(list[i]);
            else{
                if(!stack.isEmpty())
                    stack.pop();
            }
        }
        
        StringBuilder res = new StringBuilder();
        
        Stack<String> temp = new Stack<String>();
        while(!stack.isEmpty())  
            temp.push(stack.pop());
        
        while(!temp.isEmpty())
            res.append("/"+temp.pop());
        
        if(res.length()==0)
            res.append("/");
        
        return res.toString();
    }
}