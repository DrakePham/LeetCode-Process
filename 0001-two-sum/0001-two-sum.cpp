class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int length = nums.size();
        for(int i = 0 ; i < length; i++){
            if (map.find(target - nums[i]) != map.end()) return {i , map[target - nums[i]]};
            map[nums[i]] = i;
        }
        return {};
    }
};