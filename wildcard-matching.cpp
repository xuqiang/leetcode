/*
Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false


*/



    bool isMatch(const char *s, const char *p) {
        //? match one
        //* match 0,1,2,3..
        // aaaabc *c true
        const char* star = NULL;
        const char* rs = NULL;
        
        while(*s) {
            if(*s == *p || *p == '?') { //match
                s++; p++;
                continue;
            }
            if(*p == '*') { 
                star = p; // record star
                p++; //match from next p
                rs = s; // record the position of s , star match 0
                continue;
            } 
            if(star != NULL) { //if have star in front then backtrace
                p = star + 1; //reset the position of p 
                s = rs + 1; 
                rs ++; //star match 1,2,3,4,5....
                continue;
            }
            return false; //if not match return false
        }
        while(*p == '*') p++; //skip continue star
        return *p == '\0'; // successful match
    }
