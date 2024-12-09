/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
LEETCCODE-1768
Return the merged string.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int minLength = min(word1.length(), word2.length());

        for (int i = 0; i < minLength; ++i) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }

        result.append(word1.length() > minLength ? word1.substr(minLength) : word2.substr(minLength));
        
        return result;
    }
};

int main() {
    string word1 = "abc";
    string word2 = "pqr";

    Solution sol;
    string merged = sol.mergeAlternately(word1, word2);

    cout << "Merged string: " << merged << endl;

    return 0;
}














































