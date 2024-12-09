/*Given a string s, reverse only all the vowels in the string and return it.
LEETCODE-345
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char &ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
            } else if (!isVowel(s[j])) {
                j--;
            } else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s = "hello";
    cout << "Reversed vowels in string 'hello': " << solution.reverseVowels(s) << endl;

    // Test case 2
    s = "leetcode";
    cout << "Reversed vowels in string 'leetcode': " << solution.reverseVowels(s) << endl;

    // Test case 3
    s = "aeiou";
    cout << "Reversed vowels in string 'aeiou': " << solution.reverseVowels(s) << endl;

    return 0;
}