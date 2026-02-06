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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // For reversing nodes in a linked list in groups of size k
        // Instead of flipping the whole list, we break it into groups of k nodes and reverse each group separately
        // If any group at the end has fewer than k nodes, we just leave it as is

        if(!head || k == 1) return head;

        // chcek if there are atleast k nodes
        ListNode* curr = head;
        int count = 0;
        while(curr && count < k){
            curr = curr->next;
            count++;
        }

        if(count < k) return head;

        // reverse first k nodes
        ListNode* prev = nullptr;
        curr = head;
        for(int i = 0; i<k; i++){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // recursively reverse remaining list
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};