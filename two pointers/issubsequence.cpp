/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
LEETCODE - 392
A subsequence of a string is a new string that is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, vector<int>> charIndices;  // Stores all indices of each character in t
    
    // Preprocessing function to store the positions of each character in string t
    void preprocess(const string& t) {
        for (int i = 0; i < t.size(); ++i) {
            charIndices[t[i]].push_back(i);  // Store each character's index in a vector
        }
    }
    
    // Function to check if s is a subsequence of t using preprocessed indices
    bool isSubsequenceWithPreprocessing(const string& s) {
        int prevIndex = -1;  // To track the index of the last matched character in t
        
        // For each character in s, find the next valid position in t using binary search
        for (char c : s) {
            // If character doesn't exist in t, return false
            if (charIndices.find(c) == charIndices.end()) {
                return false;
            }
            
            // Use upper_bound to find the first valid index greater than prevIndex
            const auto& indices = charIndices[c];
            auto it = upper_bound(indices.begin(), indices.end(), prevIndex);
            
            // If no valid position is found, return false
            if (it == indices.end()) {
                return false;
            }
            
            // Update prevIndex to the current valid position
            prevIndex = *it;
        }
        
        return true;  // All characters in s have valid positions in t
    }
    
public:
    // Main function to check if s is a subsequence of t
    bool isSubsequence(string s, string t) {
        preprocess(t);  // Preprocess the string t
        return isSubsequenceWithPreprocessing(s);  // Check if s is subsequence using the preprocessed data
    }
};

int main() {
    Solution solution;
    string s = "abc";
    string t = "ahbgdc";
    
    if (solution.isSubsequence(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}
