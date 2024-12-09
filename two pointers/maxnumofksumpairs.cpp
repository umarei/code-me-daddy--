/*You are given an integer array nums and an integer k.
LEETCODE- 1679
In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;  // Stores the count of each number
        int operations = 0;
        
        // Iterate through each number in the array
        for (int num : nums) {
            int complement = k - num;  // Find the complement that sums to k
            
            // Check if the complement is available in the map
            if (countMap[complement] > 0) {
                // If a pair is found, reduce the count of the complement
                countMap[complement]--;
                // Increment the number of operations (valid pair found)
                operations++;
            } else {
                // Otherwise, store the count of the current number
                countMap[num]++;
            }
        }
        
        return operations;  // Return the maximum number of operations (pairs)
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    
    cout << solution.maxOperations(nums, k) << endl;  // Output: 2
    return 0;
}
