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
    ListNode* removeNodes(ListNode* head, int x) {
        if(!head) return NULL;
        head->next = removeNodes(head->next, head->val);
        return (head->val == x) ? head->next : head;;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        removeNodes(head, -101);
        return head;
    }
};