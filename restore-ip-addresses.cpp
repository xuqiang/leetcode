/*

Restore IP Addresses


Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

dfs + 剪枝

*/


class Solution {
public:

    bool dfs(string input, int number, string ipAddress, vector<string> &result){
        if(input.length() == 0){
            return false;
        }
        if(number == 3){
            int addressNumber = stoi(input);
            if(input[0] == '0'){
                if(!(input.length() == 1 && addressNumber == 0))
                    return false;
            }
            if(addressNumber <= 255){
                ipAddress = ipAddress + input;
                result.push_back(ipAddress);
                return true;
            }else{
                return false;
            }
        }else{
            if(input.length() >= 1){
                dfs(input.substr(1), number + 1, ipAddress + input.substr(0, 1) + ".", result);
            }
            if(input.length() >= 2 && input[0] != '0'){
                dfs(input.substr(2), number + 1, ipAddress + input.substr(0, 2) + ".", result);
            }
            if(input.length() >= 3 && input[0] != '0'){
                int addressNumber = stoi(input.substr(0, 3));
                if(addressNumber <= 255){
                    dfs(input.substr(3), number + 1, ipAddress + input.substr(0, 3) + ".", result);
                }
            }
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.length() == 0 || s.length() > 12){
            return result;
        }
        string temp = "";
        dfs(s, 0, temp, result);
        return result;
    }
};