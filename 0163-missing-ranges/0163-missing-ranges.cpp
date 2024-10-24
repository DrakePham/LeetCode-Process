class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0) return {{lower, upper}};
        vector<vector<int>> result;
        if(nums[0] != lower) result.push_back({lower, nums[0] - 1});
        if(nums[nums.size() - 1] != upper) nums.push_back(upper + 1);
        int left = 0;
        int right = 0;
        int length = nums.size();
        while(left < length && right < length){
            int leftValue = nums[left];
            int rightValue = nums[right];
            if(left == right) right++;
            else if(rightValue - leftValue == 1) left++;
            else if(rightValue - leftValue > 1){
                result.push_back({leftValue + 1, rightValue - 1});
                left++;
            }
        }
        return result;

    }
};