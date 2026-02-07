/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *merge(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        
        Node* res;
        
        if(a->data < b->data){
            res = a;
            res->bottom = merge(a->bottom, b);
        } else {
            res = b;
            res->bottom = merge(b->bottom, a);
        }
        
        res->next = NULL;
        return res;
    }
    
    Node *flatten(Node *head) {
        if(!head || !head->next) return head;
        
        head->next = flatten(head->next);
        
        head = merge(head, head->next);
        
        return head;
    }
};