/* You are given a string s, which contains stars *.
LEETCODE - 2390
In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '*') {
                if (!st.empty()) {
                    st.pop();  // Remove the closest non-star character
                }
            } else {
                st.push(c);  // Add the character to the stack
            }
        }

        // Build the final string from the stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Since the stack reverses the order of characters, we need to reverse the string
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "leet**cod*e";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.removeStars(s1) << endl;

    // Example 2
    string s2 = "erase*****";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.removeStars(s2) << endl;

    return 0;
}

