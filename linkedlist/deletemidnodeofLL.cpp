/*You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
LEETOCDE-2095
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.*/
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* prevSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevSlow->next = slow->next;
        delete(slow);
        return head;
    }
};

int main() {
    Solution solution;

    // Example 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(7);
    head1->next->next->next->next = new ListNode(1);
    head1->next->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next->next = new ListNode(6);
    head1 = solution.deleteMiddle(head1);
    while (head1 != NULL) {
        cout << head1->val << " ";
        head1 = head1->next;
    }
    cout << endl;

    // Example 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2 = solution.deleteMiddle(head2);
    while (head2 != NULL) {
        cout << head2->val << " ";
        head2 = head2->next;
    }
    cout << endl;

    // Example 3
    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(1);
    head3 = solution.deleteMiddle(head3);
    while (head3 != NULL) {
        cout << head3->val << " ";
        head3 = head3->next;
    }
    cout << endl;

    return 0;
}