/*Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj)
 such that row ri and column cj 
are equal.
LEETCODE-2352
A row and column pair is considered equal if they contain the same elements
 in the same order (i.e., an equal array).*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        map<vector<int>, int> mp;
        
        // Step 1: Count the frequency of each row in the map
        for (int row = 0; row < n; row++) {
            mp[grid[row]]++; // Store each row as a key and increment its frequency
        }
        
        // Step 2: Compare each column with rows
        for (int c = 0; c < n; c++) {
            vector<int> temp; // Temp vector to store the column values
            
            for (int r = 0; r < n; r++) {
                temp.push_back(grid[r][c]); // Build the column as a vector
            }
            
            // Increment count by the number of times this column matches a row
            count += mp[temp];
        }
        
        return count;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> grid1 = {
        {3, 2, 1},
        {1, 7, 6},
        {2, 7, 7}
    };
    cout << "Test 1: " << solution.equalPairs(grid1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}
    };
    cout << "Test 2: " << solution.equalPairs(grid2) << endl;

    return 0;
}
