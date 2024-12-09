/*Given an input string s, reverse the order of the words.
LEETCODE-151
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int i = 0;
        int l = 0, r = 0;
        
        int n = s.length();
        
        while (i < n) {
            while (i < n && s[i] != ' ') { 
                s[r++] = s[i++];
            }
            
            if (l < r) { 
                reverse(s.begin() + l, s.begin() + r);
                
                s[r] = ' ';
                r++;
                
                l = r;
            }
            
            i++;
        }
        
        s = s.substr(0, r - 1);
        
        return s;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s = "the sky is blue";
    cout << "Reversed words in string 'the sky is blue': " << solution.reverseWords(s) << endl;

    // Test case 2
    s = "  hello world  ";
    cout << "Reversed words in string '  hello world  ': " << solution.reverseWords(s) << endl;

    // Test case 3
    s = "a good   example";
    cout << "Reversed words in string 'a good   example': " << solution.reverseWords(s) << endl;

    return 0;
}