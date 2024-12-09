/*In the world of Dota2, there are two parties: the Radiant and the Dire.
LEETCODE 649
The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        
        // Fill the queues with the indices of the respective senators
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        
        // Simulate the rounds
        while (!radiant.empty() && !dire.empty()) {
            int r_index = radiant.front();
            int d_index = dire.front();
            radiant.pop();
            dire.pop();
            
            // The senator with the smaller index bans the other senator
            if (r_index < d_index) {
                radiant.push(r_index + n);  // Move the winner to the back of the queue
            } else {
                dire.push(d_index + n);  // Move the winner to the back of the queue
            }
        }
        
        // Return the winner based on which queue is empty
        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    Solution solution;
    string senate;

    // Test case 1
    senate = "RD";
    cout << solution.predictPartyVictory(senate) << endl; // Output: "Radiant"

    // Test case 2
    senate = "RDD";
    cout << solution.predictPartyVictory(senate) << endl; // Output: "Dire"

    // You can add more test cases here if needed.

    return 0;
}
