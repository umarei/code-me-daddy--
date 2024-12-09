/*There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
LEETCODE-1431
Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        
        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
    cout << "Result for candies = [2, 3, 5, 1, 3] and extraCandies = 3: ";
    for (bool res : result) {
        cout << res << " ";
    }
    cout << endl;
    
    // Test case 2
    candies = {4, 2, 1, 1, 2};
    extraCandies = 1;
    result = solution.kidsWithCandies(candies, extraCandies);
    cout << "Result for candies = [4, 2, 1, 1, 2] and extraCandies = 1: ";
    for (bool res : result) {
        cout << res << " ";
    }
    cout << endl;
    
    // Test case 3
    candies = {12, 1, 12};
    extraCandies = 10;
    result = solution.kidsWithCandies(candies, extraCandies);
    cout << "Result for candies = [12, 1, 12] and extraCandies = 10: ";
    for (bool res : result) {
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}