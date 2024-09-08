class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int s1 = m - 1;
        int s2 = n - 1;
        while( s2 >=0){
            if( s1 >=0 && nums1[s1] > nums2[s2]){
                nums1[index--] = nums1[s1--];
            }else{
                nums1[index--] = nums2[s2--];
            }
        }

    }
};

// [1,2,2,3,5,6]
//    i
// [1,2,3,0,0,0]
//    1
//  [2,5,6]
// 2

