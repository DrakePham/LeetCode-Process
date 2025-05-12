class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> pre = vector<int>(l , 1);
        vector<int> post = vector<int>(l , 1);
        for(int i = 0 ; i < l; i++){
            if( i == 0) continue;
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for(int i = l - 2; i >= 0; i--){
            post[i] = post[i + 1] * nums[i + 1];
        }
        for(int i = 0 ; i < l ; i++){
            nums[i] = pre[i] * post[i];
        }
        return nums;
    }
};

// have a prefix product at index i : pre[i] == arr[0] .... arr[i - 1];// if i == 0
// have a postfix product at index i : post[i] == arr[n - 1] .... arr[ i  + 1] // if i == n - 1

// nums[i] == pre[i] * post[i]

