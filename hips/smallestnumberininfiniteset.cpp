/*You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
LEETCODE-2336
Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.*/

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
    set<int> st;
    
    int currSmallest;
    
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        
        if(!st.empty()) {
            result = *st.begin();
            st.erase(st.begin()); //or, st.erase(result) also works
        } else {
            result = currSmallest;
            currSmallest += 1;
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;
        
        st.insert(num);
    }
};

int main() {
    SmallestInfiniteSet smallestInfiniteSet;
    smallestInfiniteSet.addBack(2);
    smallestInfiniteSet.addBack(1);
    cout << smallestInfiniteSet.popSmallest() << endl; // 1
    cout << smallestInfiniteSet.popSmallest() << endl; // 2
    cout << smallestInfiniteSet.popSmallest() << endl; // 3
    smallestInfiniteSet.addBack(1);
    cout << smallestInfiniteSet.popSmallest() << endl; // 1
    cout << smallestInfiniteSet.popSmallest() << endl; // 4
    return 0;
}