/*Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
LEETCODE- 216
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        backtrack(result, currentCombination, k, n, 1);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& currentCombination, int k, int target, int start) {
        if (currentCombination.size() == k && target == 0) {
            result.push_back(currentCombination); // valid combination
            return;
        }

        for (int i = start; i <= 9; ++i) {
            // Skip if remaining sum is less than current number
            if (i > target) break;
            
            // Make the choice to include 'i'
            currentCombination.push_back(i);
            
            // Recurse with reduced target and next number
            backtrack(result, currentCombination, k, target - i, i + 1);
            
            // Undo the choice (backtrack)
            currentCombination.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int k = 3, n = 7;
    vector<vector<int>> result = solution.combinationSum3(k, n);

    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
