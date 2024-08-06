class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};


// if i == i-1 and i = i+ n/2 - 1
// 7/2 = 3
// 1112222