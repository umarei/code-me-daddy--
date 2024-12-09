/*For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
LEETCCODE- 1071
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the greatest common divisor (GCD) of two numbers
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Function to find the GCD of two strings
    string gcdOfStrings(string str1, string str2) {
        // Check if the concatenation of str1 and str2 is the same as the concatenation of str2 and str1
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Calculate the GCD of the lengths of str1 and str2
        int gcdLength = gcd(str1.length(), str2.length());
        
        // Return the substring of str1 from index 0 to gcdLength
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << "GCD of '" << str1 << "' and '" << str2 << "' is: " << solution.gcdOfStrings(str1, str2) << endl;
    
    // Test case 2
    str1 = "ABABAB";
    str2 = "ABAB";
    cout << "GCD of '" << str1 << "' and '" << str2 << "' is: " << solution.gcdOfStrings(str1, str2) << endl;
    
    // Test case 3
    str1 = "LEET";
    str2 = "CODE";
    cout << "GCD of '" << str1 << "' and '" << str2 << "' is: " << solution.gcdOfStrings(str1, str2) << endl;
    
    return 0;
}