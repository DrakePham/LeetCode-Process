class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >minHeap;
        
        set<pair<int, int>> s;
        vector<vector<int>> result;
        s.insert({0,0});
        minHeap.push({nums1[0]+ nums2[0], 0, 0});
        
        while(k){
            
                if(minHeap.empty()) return result;
                vector<int> temp = minHeap.top();
                int p1 = temp[1];
                int p2 = temp[2];
                result.push_back({nums1[p1], nums2[p2]});
                k--;
                minHeap.pop();
            
            if(p1+1 < nums1.size() and s.find({p1+1, p2}) == s.end()) {
                s.insert({p1+1,p2});
                minHeap.push({nums1[p1+1]+ nums2[p2], p1+1, p2});
            }

            if(p2+1 < nums2.size() and s.find({p1, p2+1}) == s.end()) {
                s.insert({p1,p2+1});
                minHeap.push({nums1[p1]+ nums2[p2+1], p1, p2+1});
            }
        }

        return result;
    }
};