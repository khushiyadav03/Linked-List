class Solution {
  public:
    Node* segregate(Node* head) {
        if (head == nullptr) return head;

        // Dummy nodes
        Node* zeroDummy = new Node(-1);
        Node* oneDummy  = new Node(-1);
        Node* twoDummy  = new Node(-1);

        Node* zeroTail = zeroDummy;
        Node* oneTail  = oneDummy;
        Node* twoTail  = twoDummy;

        Node* curr = head;

        // Distribute nodes into 0s, 1s, and 2s lists
        while (curr) {
            if (curr->data == 0) {
                zeroTail->next = curr;
                zeroTail = curr;
            } 
            else if (curr->data == 1) {
                oneTail->next = curr;
                oneTail = curr;
            } 
            else {
                twoTail->next = curr;
                twoTail = curr;
            }
            curr = curr->next;
        }

        // Properly terminate lists
        twoTail->next = nullptr;
        oneTail->next = twoDummy->next;
        zeroTail->next = oneDummy->next ? oneDummy->next : twoDummy->next;

        // New head
        Node* newHead = zeroDummy->next;

        // Cleanup dummy nodes
        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;

        return newHead;
    }
};
