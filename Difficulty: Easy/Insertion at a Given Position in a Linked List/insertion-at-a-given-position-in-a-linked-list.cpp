class Solution {
  public:
    Node* insertAtHead(Node* head, int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* insertPos(Node* head, int pos, int val) {
        // insert at head
        if (pos == 1) {
            return insertAtHead(head, val);
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // position out of bounds
        if (temp == NULL) {
            return head;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
};
