/*Two strings are considered close if you can attain one from the other using the 
following operations:
LEETCODE-1657
Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another 
existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close,
 and false otherwise.*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // If the lengths of the two strings are not the same, return false
        if (m != n)
            return false;
        
        // Frequency vectors to store character frequencies
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        // Count the frequency of each character in both strings
        for (int i = 0; i < m; i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];
            
            int idx1 = ch1 - 'a';
            int idx2 = ch2 - 'a';
            
            freq1[idx1]++;
            freq2[idx2]++;
        }
        
        // 1st check: Both strings should have the same set of characters
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != 0 && freq2[i] != 0) continue; // Both have the same character
            if (freq1[i] == 0 && freq2[i] == 0) continue; // Both don't have the character
            return false; // If one string has a character that the other doesn't
        }
        
        // 2nd check: Sort the frequencies and compare
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));
        
        // If sorted frequencies match, the strings are "close"
        return freq1 == freq2;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    
    // Example 1
    string word1 = "abc";
    string word2 = "bca";
    cout << "Test 1: " << (solution.closeStrings(word1, word2) ? "true" : "false") << endl;

    // Example 2
    word1 = "a";
    word2 = "aa";
    cout << "Test 2: " << (solution.closeStrings(word1, word2) ? "true" : "false") << endl;

    // Example 3
    word1 = "cabbba";
    word2 = "abbccc";
    cout << "Test 3: " << (solution.closeStrings(word1, word2) ? "true" : "false") << endl;

    return 0;
}
