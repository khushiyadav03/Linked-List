/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(!head || !head->next) return head;
        
        Node* curr = head;
        Node* temp = NULL;
        while(curr){
            // swap prev & next
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            
            // move to next node which is prev now
            curr = curr->prev;
        }
        return temp->prev;
        
    }
};