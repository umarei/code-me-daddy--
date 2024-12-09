/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/
/*LEETOCDE- 206*/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  
        ListNode* curr = head;     
        ListNode* next = nullptr;  

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;           
            curr = next;           
        }

        return prev;  
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
    head1 = solution.reverseList(head1);
    while (head1 != NULL) {
        cout << head1->val << " ";
        head1 = head1->next;
    }
    cout << endl;

    // Example 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2 = solution.reverseList(head2);
    while (head2 != NULL) {
        cout << head2->val << " ";
        head2 = head2->next;
    }
    cout << endl;

    // Example 3
    ListNode* head3 = NULL;
    head3 = solution.reverseList(head3);
    if (head3 == NULL) {
        cout << "[]" << endl;
    } else {
        while (head3 != NULL) {
            cout << head3->val << " ";
            head3 = head3->next;
        }
        cout << endl;
    }

    return 0;
}