class Solution {
public:

    bool isValidPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while(start < end){
            if(s[start] == s[end]){
                start++;
                end--;
                continue;
            }
            return isValidPalindrome(s, start + 1, end) || isValidPalindrome(s, start, end - 1);
        }
        return true;
    }
};

               