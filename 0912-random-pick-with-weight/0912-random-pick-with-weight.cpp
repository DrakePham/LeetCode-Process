class Solution {
public:
    int sum = 0;
    vector<int> searchRange;
    Solution(vector<int>& w) {
        for(auto& num:w) {
            sum += num;
            searchRange.push_back(sum);
        }
        
    }
    
    int pickIndex() {
        
        int random_number = rand() % searchRange.back();
        auto it = upper_bound(searchRange.begin(), searchRange.end(), random_number);
        int index = it - searchRange.begin();

        return index; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */