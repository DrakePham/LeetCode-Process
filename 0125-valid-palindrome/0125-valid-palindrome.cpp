class Solution {
public:
    string modifyInput(string s){
        string modifiedString = "";
        for(auto c:s){
            if(isalnum(c)) modifiedString += tolower(c);
        }
        return modifiedString;
    }
    bool isPalindrome(string s) {
        string modifiedString = modifyInput(s);
        int l = modifiedString.length();
        for(int i = 0 ; i < l/2; i++){
            if(modifiedString[i] != modifiedString[l - 1 - i]){
                return false;
            }
        }
        return true;
    }
};