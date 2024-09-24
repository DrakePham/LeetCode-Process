class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> freFix (n + 2, 0);
        vector<int> postFix (n + 2, 0);

        for(int i = 1; i < n + 1; i++){
            freFix[i] = nums[i - 1] + freFix[i - 1];
        }

        for(int i = n; i >= 1; i--){
            postFix[i] = nums[i - 1] + postFix[i + 1];
        }

        for(int i = 1; i < n + 1; i++){
            if(freFix[i - 1] == postFix[i + 1]) return i - 1;
        }

        return -1;
    }
};


//  [2,3,-1,8,4]
// 0 2 5  4 12 16 0
// 016 14 11 12  4   0