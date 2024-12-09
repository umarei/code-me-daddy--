/*Given an encoded string, return its decoded string.

// LEETCODE 394
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 10^5.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;  // Stack to store numbers
        stack<string> str_stack;  // Stack to store substrings
        string current_string = "";  // Current substring being constructed
        int current_num = 0;  // Current number being constructed
        
        for (char c : s) {
            if (isdigit(c)) {
                // Construct the full number
                current_num = current_num * 10 + (c - '0');
            } else if (c == '[') {
                // Push the current number and substring onto their respective stacks
                num_stack.push(current_num);
                str_stack.push(current_string);
                current_string = "";  // Reset the current substring
                current_num = 0;  // Reset the current number
            } else if (c == ']') {
                // Pop from stacks and decode the string
                string temp = current_string;
                current_string = str_stack.top();
                str_stack.pop();
                int repeat_count = num_stack.top();
                num_stack.pop();
                
                // Repeat the decoded substring and append to the string popped from str_stack
                while (repeat_count-- > 0) {
                    current_string += temp;
                }
            } else {
                // Append characters to the current substring
                current_string += c;
            }
        }
        
        return current_string;
    }
};

int main() {
    Solution solution;
    
    // Example test cases
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";
    
    cout << "Decoded string for '" << s1 << "': " << solution.decodeString(s1) << endl;
    cout << "Decoded string for '" << s2 << "': " << solution.decodeString(s2) << endl;
    cout << "Decoded string for '" << s3 << "': " << solution.decodeString(s3) << endl;
    
    return 0;
}
