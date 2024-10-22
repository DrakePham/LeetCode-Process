class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int length = heights.size();
        vector<bool> isViewable = vector<bool>(length, false);
        int currentMaxHeight = 0;
        for(int i = length - 1; i >= 0; i--){
            int currentHeight = heights[i];
            if(currentHeight > currentMaxHeight){
                isViewable[i] = true;
                currentMaxHeight = currentHeight;
            }
        }

        vector<int> result;

        for(int i = 0; i < length; i++){
            if(isViewable[i]) result.push_back(i);
        }

        return result;
    }
};