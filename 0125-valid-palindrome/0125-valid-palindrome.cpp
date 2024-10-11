class Solution {
public:
    void processInput(string& s){
        string temp;
        for(auto& c:s){
            if(isalnum(c)) temp += tolower(c);
        }
        s = temp;
    }
    bool isPalindrome(string s) {
        processInput(s);
        int left = 0;
        int right = s.length() - 1;
        while(left <= right){
            char leftCh = s[left];
            char rightCh = s[right];
            if(leftCh != rightCh) return false;
            left++;
            right--;
        }
        return true;
    }
};