class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> isMark(n, false);  // Track whether an index is marked
        vector<long long> result;
        long long unmarkedSum = 0;      // Sum of unmarked numbers
        int unmarkedNum = n;            // Number of unmarked elements
        
        // Min-heap to store values with indices in a decreasing order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Initialize the sum and the heap
        for (int i = 0; i < n; i++) {
            unmarkedSum += nums[i];
            minHeap.push({nums[i], i});
        }

        // Process each query
        for (auto& query : queries) {
            int k = query[1];   // Number of smallest elements to mark
            int idx = query[0]; // Index to mark

            // If the index is unmarked, mark it and decrease the sum
            if (!isMark[idx]) {
                isMark[idx] = true;
                unmarkedSum -= nums[idx];
                unmarkedNum--;
            }

            // Find k smallest unmarked numbers using the heap
            while (k > 0 && unmarkedNum > 0) {
                auto [smallestVal, smallestIdx] = minHeap.top();

                // If the top element is already marked, pop it
                if (isMark[smallestIdx]) {
                    minHeap.pop();
                    continue;
                }

                // Mark the smallest unmarked element
                isMark[smallestIdx] = true;
                unmarkedSum -= smallestVal;
                unmarkedNum--;
                k--;
                minHeap.pop(); // Remove it from the heap after marking
            }

            // Add the current unmarked sum to the result
            result.push_back(unmarkedSum);
        }

        return result;
    
    }
};


// result
// unmarkedSum
// isMark: bool : array
// unmarkedNum
// minHeap<int, vector<int>>, decearsing order
// for each query in queries
//     if the unmarkedNum == 0 return 0;
//     1. if the index is not mark, mark the index, decrease the unmarkedSum
//     2. while loop to find k smallest number
//         2.1 with each smallest number from the minHeap, if the it unmarked, mark the index, decrease the unmarkedSum
//         2.2 with each smallest number from the minHeap, if it is marked, pop that index number out of the vector, move continue;
//     push the unmarkSum into the result

// return result



