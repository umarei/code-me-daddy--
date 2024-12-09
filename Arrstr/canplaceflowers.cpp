/*You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
LEETCODE- 605
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int l = flowerbed.size();
        
        if(n == 0)
            return true;
        
        
        for(int i = 0; i<l; i++) {
            
            if(flowerbed[i] == 0) {
                
                bool leftEmpty   = (i == 0) || (flowerbed[i-1] == 0);
                
                bool rightEmpty  = (i == l-1) || (flowerbed[i+1] == 0);
                
                if(leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    n--;
                    if(n == 0)
                        return true;
                }
                
            }
            
        }
        
        return false;
        
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    cout << "Can place " << n << " flowers in flowerbed [1, 0, 0, 0, 1]: " << (solution.canPlaceFlowers(flowerbed, n) ? "true" : "false") << endl;
    
    // Test case 2
    flowerbed = {1, 0, 0, 0, 1};
    n = 2;
    cout << "Can place " << n << " flowers in flowerbed [1, 0, 0, 0, 1]: " << (solution.canPlaceFlowers(flowerbed, n) ? "true" : "false") << endl;
    
    // Test case 3
    flowerbed = {0, 0, 1, 0, 0};
    n = 2;
    cout << "Can place " << n << " flowers in flowerbed [0, 0, 1, 0, 0]: " << (solution.canPlaceFlowers(flowerbed, n) ? "true" : "false") << endl;
    
    return 0;
}