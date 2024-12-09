/*In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
LEETCODE-2130
For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.*/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        int maxSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf != nullptr) {
            int sum = firstHalf->val + secondHalf->val;
            maxSum = max(maxSum, sum);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxSum;
    }
};

int main() {
    Solution solution;

    // Example 1
    ListNode* head1 = new ListNode(5);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);
    cout << solution.pairSum(head1) << endl;

    // Example 2
    ListNode* head2 = new ListNode(4);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    cout << solution.pairSum(head2) << endl;

    // Example 3
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(100000);
    cout << solution.pairSum(head3) << endl;

    return 0;
}