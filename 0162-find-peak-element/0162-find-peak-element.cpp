class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mid + 1 < nums.size() && nums[mid + 1] > nums[mid]){
                left = mid + 1;
            }else if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]){
                right = mid - 1;
            }else return mid;
        }
        return -1;
    }
    
};

// 1,2,1,3,5,6,4
// left = 5
// right = 6
// mid = 4

// i-1 , i , i + 1

// i>i-1,i+1-> peak
// else i+1 > i find in the right side
// else i- 1 > i find in the left side






