class Solution {
  public:
    Node* delPos(Node* head, int pos) {
        if (head == NULL) return head;

        // Case 1: delete head (pos = 1)
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return head;
        }

        // Traverse to the pos-th node
        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        // If position is invalid
        if (temp == NULL) return head;

        // Adjust links
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        delete temp;
        return head;
    }
};
