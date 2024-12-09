/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints 
of the ith line are (i, 0) and (i, height[i]).
LEETCODE - 11
Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;  // Left pointer starts at the beginning
        int right = height.size() - 1;  // Right pointer starts at the end
        int max_area = 0;  // Initialize max_area to 0
        
        // Iterate while the left pointer is less than the right pointer
        while (left < right) {
            // Calculate the height of the container, using the shorter line
            int h = min(height[left], height[right]);
            // Calculate the current area (height * width)
            int area = h * (right - left);
            // Update the maximum area
            max_area = max(max_area, area);
            
            // Move the pointer at the shorter line inward to explore larger areas
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        
        return max_area;  // Return the maximum area found
    }
};

int main() {
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(height) << endl;  // Output: 49
    return 0;
}
