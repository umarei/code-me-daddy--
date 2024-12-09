/*Given an array of integers arr, return true if the number of 
LEETCODE- 1207
occurrences of each value in the array is unique or false otherwise.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        
        // Count occurrences of each number
        for (int num : arr) {
            countMap[num]++;
        }
        
        unordered_set<int> freqSet;
        
        // Check for unique occurrences
        for (const auto& pair : countMap) {
            if (freqSet.find(pair.second) != freqSet.end()) {
                return false;  // If frequency is already seen, return false
            }
            freqSet.insert(pair.second);  // Insert the frequency into the set
        }
        
        return true;  // All frequencies are unique
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    vector<int> arr2 = {1, 2};
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    
    cout << "Unique occurrences (arr1): " << (sol.uniqueOccurrences(arr1) ? "true" : "false") << endl; // Output: true
    cout << "Unique occurrences (arr2): " << (sol.uniqueOccurrences(arr2) ? "true" : "false") << endl; // Output: false
    cout << "Unique occurrences (arr3): " << (sol.uniqueOccurrences(arr3) ? "true" : "false") << endl; // Output: true
    
    return 0;
}
