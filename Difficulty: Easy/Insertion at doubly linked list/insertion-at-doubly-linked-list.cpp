class Solution {
  public:
    Node* insertAtPos(Node* head, int pos, int data) {
        Node* temp = head;

        // move to the pos-th node (1-based, insert AFTER it)
        for (int i = 1; i <= pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return head;

        Node* newNode = new Node(data);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;

        return head;
    }
};
