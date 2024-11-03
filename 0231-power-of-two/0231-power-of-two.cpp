class Solution {
public:
    bool isPowerOfTwo(int n) {
        long currentValue = 1;
        while(currentValue < n){
            currentValue <<= 1;
        }
        return currentValue == n ? true : false;
    }
};