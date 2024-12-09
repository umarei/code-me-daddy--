/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
LEETCODE-328
The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.*/
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenHead = even;
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            odd=odd->next;

            even->next=even->next->next;
            even=even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main() {
    Solution solution;

    // Example 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    head1 = solution.oddEvenList(head1);
    while (head1 != NULL) {
        cout << head1->val << " ";
        head1 = head1->next;
    }
    cout << endl;

    // Example 2
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(5);
    head2->next->next->next->next = new ListNode(6);
    head2->next->next->next->next->next = new ListNode(4);
    head2->next->next->next->next->next->next = new ListNode(7);
    head2 = solution.oddEvenList(head2);
    while (head2 != NULL) {
        cout << head2->val << " ";
        head2 = head2->next;
    }
    cout << endl;

    return 0;
}