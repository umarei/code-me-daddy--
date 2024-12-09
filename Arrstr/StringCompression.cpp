/*Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:
LEETCODE- 443
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int i = 0;    // Pointer to traverse through the input array
        int index = 0;  // Pointer to update the compressed characters in the array
        
        while(i < n) {
            char curr = chars[i];  // Current character
            int count = 0;  // Count of the current character
            
            // Count the consecutive repeating characters
            while(i < n && chars[i] == curr) {
                i++;
                count++;
            }
            
            // Update the character at the current index
            chars[index] = curr;
            index++;
            
            // If count > 1, convert count to a string and update it in the array
            if(count > 1) {
                string count_str = to_string(count);
                for(char &ch : count_str) {
                    chars[index] = ch;
                    index++;
                }
            }
        }
        
        // Return the new length of the compressed array
        return index;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength1 = sol.compress(chars1);
    cout << "New Length: " << newLength1 << endl;
    cout << "Compressed chars: ";
    for(int i = 0; i < newLength1; i++) {
        cout << chars1[i];
    }
    cout << endl;
    
    // Test case 2
    vector<char> chars2 = {'a'};
    int newLength2 = sol.compress(chars2);
    cout << "New Length: " << newLength2 << endl;
    cout << "Compressed chars: " << chars2[0] << endl;
    
    // Test case 3
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int newLength3 = sol.compress(chars3);
    cout << "New Length: " << newLength3 << endl;
    cout << "Compressed chars: ";
    for(int i = 0; i < newLength3; i++) {
        cout << chars3[i];
    }
    cout << endl;

    return 0;
}
