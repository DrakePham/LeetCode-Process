class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result = 0;
        sort(arr2.begin(), arr2.end());
        for(int i = 0 ; i < arr1.size(); i++){
            bool isGreaterThanD = true;
            auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
            if(it != arr2.end() && abs(arr1[i] - *it) <= d) isGreaterThanD = false;
            if(it != arr2.begin() && abs(arr1[i] - *(it - 1)) <= d) isGreaterThanD = false;  
            if(isGreaterThanD) result++;
        }

        return result;
    }
};