/*

Valid Number

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click
 the reload button  to reset your code definition.




*/


public class Solution {
    public boolean isNumber(String s) {
        if (s == null) {
            return false;
        }
        
        // cut the leading spaces and tail spaces.
        String sCut = s.trim();
        
        /*
        Some examples:
        "0" => true 
        " 0.1 " => true
        "abc" => false
        "1 a" => false
        "2e10" => true
        */
        
        int len = sCut.length();
        
        boolean num = false;
        boolean exp = false;
        boolean dot = false;
        
        for (int i = 0; i < len; i++) {
            char c = sCut.charAt(i);
            if (c == 'e') {
                if (!num || exp) {
                    return false;
                }
                exp = true;
                num = false; // Should be: 2e2 , so there should be number follow "e"
            } else if (c <= '9' && c >= '0') {
                num = true;
            } else if (c == '.') {
                if (exp || dot) { // can't be: e0.2 can't be: ..
                    return false;
                }
                dot = true;
            } else if (c == '+' || c == '-') {
                if (i != 0 && sCut.charAt(i - 1) != 'e') { // filter : " 005047e+6", this is true.
                    return false;
                }
            } else {
                // invalid character.
                return false;
            }
        }
        
        return num;
    }
}