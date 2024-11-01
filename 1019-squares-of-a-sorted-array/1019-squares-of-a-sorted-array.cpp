class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length, 0);
        int l = 0;
        int r = length - 1;
        int index = length - 1;
        while(l < r && index >=0){
            if(abs(nums[l]) > abs(nums[r])){
                result[index] = pow(nums[l], 2);
                index--;
                l++;
            }else{
                result[index] = pow(nums[r], 2);
                index--;
                r--;
            }
        }
        result[index] = pow(nums[r], 2);
        return result;

    }
};

// [-4,-1,0,3,10]
//        |        
//        |

// 0,1,9,16,20
// |
