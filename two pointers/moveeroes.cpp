/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
LEEYCODE- 283
Note that you must do this in-place without making a copy of the array.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;  // pointer to track the position for the next non-zero element
        int n = nums.size();
        
        for (int right = 0; right < n; ++right) {
            if (nums[right] != 0) {
                // Swap the current non-zero element with the element at the 'left' pointer
                swap(nums[left], nums[right]);
                left++;  // Move the 'left' pointer to the next position
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);

    // Print the modified array
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}
