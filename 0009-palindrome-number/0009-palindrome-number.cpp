class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string number = to_string(x);
        for(int i = 0 ; i < number.length() / 2; i++){
            if(number[i] != number[number.length() - 1 - i]) return false;
        } 
        return true;
    }
};