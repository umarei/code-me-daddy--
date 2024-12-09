/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
LEETCODE-17
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string currentCombination;
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        backtrack(result, currentCombination, digits, 0, mapping);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string& currentCombination, const string& digits, int index, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(result, currentCombination, digits, index + 1, mapping);
            currentCombination.pop_back(); // undo choice
        }
    }
};

int main() {
    Solution solution;
    string digits = "23";
    vector<string> combinations = solution.letterCombinations(digits);
    
    for (const string& combo : combinations) {
        cout << combo << " ";
    }
    return 0;
}
