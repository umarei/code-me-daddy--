/*Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
LEETCODE- 2215
answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Use unordered sets to store distinct elements from nums1 and nums2
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        
        // Create a 2D vector to store the answer
        vector<vector<int>> ans(2);
        
        // Find elements in st1 that are not in st2 (nums1 but not nums2)
        for (int num : st1) {
            if (st2.find(num) == st2.end()) {
                ans[0].push_back(num);
            }
        }
        
        // Find elements in st2 that are not in st1 (nums2 but not nums1)
        for (int num : st2) {
            if (st1.find(num) == st1.end()) {
                ans[1].push_back(num);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    
    vector<vector<int>> result = sol.findDifference(nums1, nums2);
    
    // Output the result
    cout << "Distinct in nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << "\nDistinct in nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
