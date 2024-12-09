/*You have a RecentCounter class which counts the number of recent requests within a certain time frame.
LEETCODE- 933
Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.*/

#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        // Initialize the deque to store request times
    }
    
    int ping(int t) {
        // Add the new request time to the deque
        requests.push_back(t);
        
        // Remove requests that are outside the 3000 milliseconds window
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop_front();
        }
        
        // Return the number of requests in the current window
        return requests.size();
    }
    
private:
    deque<int> requests;  // Store the request times
};

// Example usage
int main() {
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << endl;     // Output: 1
    cout << obj->ping(100) << endl;   // Output: 2
    cout << obj->ping(3001) << endl;  // Output: 3
    cout << obj->ping(3002) << endl;  // Output: 3
    
    delete obj;
    return 0;
}
