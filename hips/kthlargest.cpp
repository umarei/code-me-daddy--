/*Given an integer array nums and an integer k, return the kth largest element in the array.
LEETCODE - 215
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    int findKthLargest(vector<int>& nums, int k) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int kthLargest = solution.findKthLargest(nums, k);
    cout << "Kth Largest Element: " << kthLargest << endl;
    return 0;
}