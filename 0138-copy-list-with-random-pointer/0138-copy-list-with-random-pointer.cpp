class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* curr = head;

        // insert copy nodes
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // assign random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // separate the lists
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        curr = head;

        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return dummy->next;
    }
};
