/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's 
in the array 
LEETCODE-1004
if you can flip at most k 0's.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;   // Two pointers for sliding window
        int max_length = 0;        // To track the maximum length of subarray
        int zero_count = 0;        // To count the number of zeros in the current window

        // Traverse the array with the `right` pointer
        while (right < nums.size()) {
            // If current element is 0, increase the zero count
            if (nums[right] == 0) {
                zero_count++;
            }

            // If the count of zeros exceeds `k`, move the `left` pointer to reduce the window size
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;  // Reduce the zero count as we move `left` pointer
                }
                left++;  // Shrink the window from the left
            }

            // Calculate the current window size and update max_length
            max_length = max(max_length, right - left + 1);
            right++;  // Expand the window by moving the `right` pointer
        }

        return max_length;  // Return the maximum length of subarray found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << solution.longestOnes(nums, k) << endl;  // Output: 6
    return 0;
}
