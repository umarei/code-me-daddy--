/*You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
LEETCODE- 2462
You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        
        long long ans = 0;
        
        int hired = 0;
        int i = 0;
        int j = n-1;
        
        while(hired < k){
            
            while(pq1.size() < candidates && i<=j) 
                pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) 
                pq2.push(costs[j--]);
            
            
            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;
            
            if(a <= b){
                ans += a;
                pq1.pop();
            } else {
                ans += b;
                pq2.pop();
            }
            
            hired++;
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> costs = {17,12,10,2,7,2,11,20,8};
    int k = 3;
    int candidates = 4;
    long long totalCost = solution.totalCost(costs, k, candidates);
    cout << "Total Cost: " << totalCost << endl;
    return 0;
}