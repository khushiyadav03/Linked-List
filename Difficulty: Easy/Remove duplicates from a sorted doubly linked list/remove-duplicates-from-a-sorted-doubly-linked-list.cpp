/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        Node* curr = head;
        while(curr != NULL && curr->next != NULL){
            if(curr->data == curr->next->data){
                // skip the next noed
                Node* temp = curr->next;
                curr->next = temp->next;
                
                // update prev pointers of the node after duplicate
                if(temp->next != NULL){
                    temp->next->prev = curr;
                }
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};