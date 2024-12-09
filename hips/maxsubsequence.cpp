/*You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

LEETCODE- 2542
For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums1.size(); i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());
        
        long long maxScore = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < pairs.size(); i++) {
            sum += pairs[i].second;
            pq.push(pairs[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                maxScore = max(maxScore, sum * pairs[i].first);
            }
        }
        
        return maxScore;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 1, 14, 12};
    vector<int> nums2 = {11, 7, 13, 6};
    int k = 3;
    long long maxScore = solution.maxScore(nums1, nums2, k);
    cout << "Maximum Score: " << maxScore << endl;
    return 0;
}

