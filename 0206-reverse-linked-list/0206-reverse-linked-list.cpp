/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Base case:
        // If list is empty OR only one node is present,
        // that node itself is the reversed list
        if(head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the remaining list
        // newHead will always point to the head of the reversed sublist
        ListNode* newHead = reverseList(head->next);

        // At this point:
        // head -> next is the last node of the reversed sublist
        // So we make next node point back to current head
        head->next->next = head;

        // Break the original link to avoid cycle
        head->next = NULL;

        // Return the head of reversed list
        return newHead;
    }
};
