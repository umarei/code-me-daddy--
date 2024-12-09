/*Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
LEETCODE- 1456
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // Function to find the maximum number of vowels in a substring of length k
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;  // Two pointers for the sliding window
        int maxV = 0, count = 0;  // maxV to store maximum vowels, count to store current vowels

        // Traverse the string using sliding window
        while (j < n) {
            // Add the character at the end of the window if it's a vowel
            if (isVowel(s[j])) {
                count++;
            }

            // When window size reaches k
            if (j - i + 1 == k) {
                // Update the maximum vowels found
                maxV = max(maxV, count);
                
                // Remove the character at the start of the window if it's a vowel
                if (isVowel(s[i])) {
                    count--;
                }
                
                // Slide the window by moving the left pointer
                i++;
            }
            
            // Expand the window by moving the right pointer
            j++;
        }

        return maxV;  // Return the maximum number of vowels found in any window
    }
};

int main() {
    Solution solution;
    string s = "abciiidef";
    int k = 3;
    cout << solution.maxVowels(s, k) << endl;  // Output: 3
    return 0;
}
