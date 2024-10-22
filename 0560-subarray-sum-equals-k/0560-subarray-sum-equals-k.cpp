class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int result = 0;
       unordered_map<int, int> map;
       int currentSum = 0;
       map[0] = 1;
       for(auto& num:nums){
            currentSum += num;
            int diff = currentSum - k;
            if(map.find(diff) != map.end()){
                result += map[diff];
            }
            map[currentSum] += 1;
       }
       return result;
    }
};