/*Given a binary array nums, you should delete one element from it.
LEETCODE- 1493
Return the size of the longest non-empty subarray
 containing only 1's in the resulting array. Return 0 if there is no such subarray.*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0; // Left pointer for sliding window
        int j = 0; // Right pointer for sliding window
        int last_zero_idx = -1; // To store the index of last encountered zero
        int result = 0; // Result to store the length of the longest subarray
        
        while (j < nums.size()) {
            if (nums[j] == 0) {
                i = last_zero_idx + 1; // Shift left pointer to one position after last zero
                last_zero_idx = j; // Update the last zero position to current position
            }
            result = max(result, j - i); // Update result with the maximum length of subarray
            j++; // Move right pointer
        }
        
        // To handle the edge case where there are no zeros, we return result-1.
        return result;
    }
};
