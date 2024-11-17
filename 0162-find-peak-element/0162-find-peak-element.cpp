class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int indexResult = 0;
        int currentValue = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > currentValue){
                currentValue = nums[i];
                indexResult = i;
            }
        }
        return indexResult;
    }
};


