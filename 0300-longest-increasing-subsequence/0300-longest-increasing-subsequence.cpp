class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = {nums[0]};
        for(int i = 1; i < nums.size(); i++){
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(it == dp.end()) {
                dp.push_back(nums[i]);
            }else{
                int index = it - dp.begin();
                dp[index] = nums[i]; 
            }
        }
        return dp.size();
    }
};

// plan:

// if we want to find the max sub array of the current index, we need to find the max subarray of the previous index

// ex [2,1,3,4]

// dp[3]=1
// dp[2]= max(1+dp[3])
//               3<4
// dp[1] = max(1+dp[2],1+dp[3])
//                1<3   1<4
// dp[0]= max(1   ,1+dp[2],1+dp[3])   
//            2>1    2<3    2<4

// [2,1,3,4] return 3

// [1,1,1,1] dp

// i=2 j=3
// dp[2]= max(1,1+1) =2
// i=1 j=2 j=3
// dp[1]= max(1,1+2,1+1)=3
// i=0 j=2 j=3
// dp[0]= max(1,1+2,1+1) =3
// return 3

