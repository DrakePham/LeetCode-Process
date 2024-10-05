class Solution {
public:
    // Helper function to calculate the sum of the array
    int sumArr(vector<int>& nums){
        int sum = 0;
        for(auto& num : nums) sum += num;
        return sum;
    }

    // Recursive function to find subsets that sum to target
    bool solver(vector<int>& nums, vector<bool>& isTaken, int start_index, int k, int current_sum, int target) {
        // If all subsets have been successfully created
        if (k == 0) return true;
        
        // If the current subset has reached the target sum, find the next subset
        if (current_sum == target) {
            return solver(nums, isTaken, 0, k - 1, 0, target);
        }

        // Try to add elements to the current subset
        for (int i = start_index; i < nums.size(); i++) {
            if (!isTaken[i] && current_sum + nums[i] <= target) {
                isTaken[i] = true; // Mark this element as taken
                
                // Recursively try to form the subset
                if (solver(nums, isTaken, i + 1, k, current_sum + nums[i], target)) {
                    return true;
                }
                
                isTaken[i] = false; // Backtrack
                if (current_sum == 0) return false; // Early exit if no valid subset can be formed
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = sumArr(nums);
        
        // If the total sum is not divisible by k, partitioning is not possible
        if (sum % k != 0) return false;
        
        int target = sum / k;
        vector<bool> isTaken(nums.size(), false);
        
        // Sort the numbers in descending order to improve backtracking efficiency
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Start the recursive backtracking process
        return solver(nums, isTaken, 0, k, 0, target);
    }
};


// /**
//  * 
//  * 
//  * 3:13 
//  * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
//  * Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets(partition) whose sums are all equal.
//  *
//  * Example 1:
//  *
//  * Input: nums = [4,3,2,3,5,2,1], k = 4
//  * Output: true
//  * Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//  * 
//  * 
//  */


//  /*
// input : array nums , int k

// outout: return true if divide into k non emty subset, and each subset sum == together

// 1 <= k <= nums.size() <= 16
// 1 <= nums[i] <= 10000

//   number occurrance <= 4
  
// array nums : random order

// we need to use all of number from array




// smallest number

// sum of the whole array

// 4 subset smallest number to the sum of the whole array

// 1 -> 20

//   1 -> 4 subset to have the sum == 1 , 
//   2 -> 4 subset to have the sum == 2
//   3
//   ..
//   20

// return false

// * Input: nums = [4,3,2,3,5,1,1,1], k = 4
  
//  1 ->first subset:  1 , second subset [] - 
//  2 ->first subset:  2, second subset   2 , third subset  1  return
// 3
  
//   5 -> first subset:  4  1, second subset   3 2, third subset  3 2 , fourth subset 5 -> return true

//   sum of subset == sum of nums / k*/

// // [3, 1, 3, 2, 4, 2, 5]

// // [4, 3, 3, 2]
// // subsetSum = 7
// // 3, 3, 2, 2 , 1 ,1

// // 5, 3, 3, 2, 2, 2, 2, 2  subsetSum = 7 k = 3

// [5, 2], [3, 2, 2], [3, 2, 2]
// [5, 2], [3, 3]
// // fake code:

// find the sum of the whole array

// subsetSum = sum of the whole array / k 

// sort with decreaing order

// vector<bool> isTaken
// for loop  1 -> k subset
// 	 1. curSum = 0
//   for loop 
   
//     2. if (the current value from array is taken) continue;
//     3. if ( curSum + current value < subSet)
//       3.1. mark the current value, add to curSum

//     4. at the end of the array, if the curSum < subSetSum - > return false

    
// return true;

  
  
  
  
  
  
  

