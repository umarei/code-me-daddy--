/*You are given an integer array nums consisting of n elements, and an integer k.
LEETCODE- 643
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
Any answer with a calculation error less than 10-5 will be accepted.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Calculate the sum of the first `k` elements (initial window)
        int current_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }
        
        // Step 2: Initialize max_sum with the sum of the first window
        int max_sum = current_sum;
        
        // Step 3: Slide the window across the array
        for (int i = k; i < n; ++i) {
            // Adjust the window by subtracting the element that leaves and adding the element that enters
            current_sum = current_sum - nums[i - k] + nums[i];
            // Update the max_sum if the current sum is larger
            max_sum = max(max_sum, current_sum);
        }
        
        // Step 4: Return the maximum average
        return static_cast<double>(max_sum) / k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout << solution.findMaxAverage(nums, k) << endl;  // Output: 12.75
    return 0;
}
