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
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases
        if (!head || !head->next || k == 0) return head;

        ListNode* fri = head;
        ListNode* temp = head;

        // find length
        int len = 0;
        while (fri) {
            len++;
            fri = fri->next;
        }

        // reduce k
        k = k % len;
        if (k == 0) return head;

        // reset pointers
        fri = head;
        temp = head;

        // move fri k steps ahead
        while (k--) {
            fri = fri->next;
        }

        // move both until fri reaches last node
        while (fri->next != NULL) {
            fri = fri->next;
            temp = temp->next;
        }

        // rotate
        fri->next = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
