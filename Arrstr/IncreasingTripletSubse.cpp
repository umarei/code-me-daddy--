/*Given an integer array nums, return true if there exists a triple of indices (i, j, k)
LEETCODE- 334
such that i < j < k and nums[i] < nums[j] < nums[k].
If no such indices exists, return false.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize two variables to represent the smallest and second smallest numbers
        int nums1 = INT_MAX;
        int nums2 = INT_MAX;

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            int nums3 = nums[i];

            // Update nums1 if current element is smaller or equal
            if (nums3 <= nums1) {
                nums1 = nums3;
            }
            // Update nums2 if current element is between nums1 and nums2
            else if (nums3 <= nums2) {
                nums2 = nums3;
            }
            // If we find a number greater than nums2, then we have found the triplet
            else {
                return true;
            }
        }
        // No increasing triplet found
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5, 4, 3, 2, 1};
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};

    cout << boolalpha;  // Print boolean values as 'true' or 'false'

    cout << "Test Case 1: " << sol.increasingTriplet(nums1) << endl;  // Expected: true
    cout << "Test Case 2: " << sol.increasingTriplet(nums2) << endl;  // Expected: false
    cout << "Test Case 3: " << sol.increasingTriplet(nums3) << endl;  // Expected: true

    return 0;
}
