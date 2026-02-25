class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MAX;
        int result = r;
        while(l <= r){
            int k = l + (r - l)/2;
            if(canEat(piles, h, k)) {
                result = min(result, k);
                r = k - 1;
            }
            else {
                l = k + 1;
            }
        }
        return result;
    }
    int findMax (vector<int>& piles){
        int maxNum = INT_MIN;
        for(auto& num:piles){
            maxNum = max(num, maxNum);
        }
        return maxNum;
    }
    
    int findMin (vector<int>& piles){
        int minNum = INT_MAX;
        for(auto& num:piles){
            minNum = min(num, minNum);
        }
        return minNum;
    }

    bool canEat(vector<int>& piles, int h, int k){
        for(auto& pile:piles){
            h -= (pile - 1)/k + 1;
            // cout<<h<<"-";
        }
        return h >= 0;
    }
};