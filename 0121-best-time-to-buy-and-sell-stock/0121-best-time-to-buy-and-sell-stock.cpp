class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int globalMaxProfit = 0;
        int currentMin = INT_MAX;
        for(auto price:prices){
            globalMaxProfit = max(globalMaxProfit, price - currentMin);
            currentMin = min(currentMin, price);
        }
        return globalMaxProfit;
    }
};



// [7,1,5,3,6,4]
// globalMaxProfit = 4
// currentMin = 1