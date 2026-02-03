/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int key) {
        // code here
        Node* curr = *head_ref;
        while(curr != NULL){
            // if current node needs to be deleted
            if(curr->data == key){
                Node* toDelete = curr;
                
                // move curr ahead BEFORE deleting
                curr = curr->next;
                
                // if node to delete is head
                if(toDelete->prev == NULL){
                    *head_ref = toDelete->next;
                    if(*head_ref != NULL){
                        (*head_ref)->prev = NULL;
                    }
                } else {
                    toDelete->prev->next = toDelete->next;
                    if(toDelete->next != NULL){
                        toDelete->next->prev = toDelete->prev;
                    }
                }
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }
};