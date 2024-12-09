/*We are given an array asteroids of integers representing asteroids in a row.
LEETCODE- 735
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                // There's a collision
                if (abs(asteroid) > st.top()) {
                    st.pop(); // The asteroid in the stack is destroyed
                } else if (abs(asteroid) == st.top()) {
                    st.pop(); // Both asteroids are destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Current asteroid is destroyed
                    break;
                }
            }

            if (!destroyed && (st.empty() || asteroid > 0 || st.top() < 0)) {
                // If not destroyed and either the stack is empty or the current asteroid is moving right
                st.push(asteroid);
            }
        }

        // Convert stack to vector
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end()); // To get the correct order
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = sol.asteroidCollision(asteroids1);
    cout << "Input: [5, 10, -5]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Example 2
    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = sol.asteroidCollision(asteroids2);
    cout << "Input: [8, -8]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Example 3
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = sol.asteroidCollision(asteroids3);
    cout << "Input: [10, 2, -5]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); ++i) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
