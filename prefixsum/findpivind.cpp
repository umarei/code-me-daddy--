/*Given an array of integers nums, calculate the pivot index of this array.
LEETCODE- 724
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.*/
#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        // If left sum equals right sum, return the current index
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    
    return -1; // No pivot index found
}

int main() {
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {2, 1, -1};
    
    cout << "Pivot Index (nums1): " << pivotIndex(nums1) << endl; // Output: 3
    cout << "Pivot Index (nums2): " << pivotIndex(nums2) << endl; // Output: -1
    cout << "Pivot Index (nums3): " << pivotIndex(nums3) << endl; // Output: 0
    
    return 0;
}
