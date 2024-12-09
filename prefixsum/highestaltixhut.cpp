/*There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.
LEETCODE-1732
You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.*/
#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int maxAltitude = 0;
    int currentAltitude = 0;
    
    // Iterate through gain array
    for (int g : gain) {
        currentAltitude += g; // Update current altitude
        maxAltitude = max(maxAltitude, currentAltitude); // Track max altitude
    }
    
    return maxAltitude;
}

int main() {
    vector<int> gain1 = {-5, 1, 5, 0, -7};
    vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};
    
    cout << "Highest Altitude (gain1): " << largestAltitude(gain1) << endl; // Output: 1
    cout << "Highest Altitude (gain2): " << largestAltitude(gain2) << endl; // Output: 0
    
    return 0;
}
