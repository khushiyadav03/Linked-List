// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        if(head == NULL) return ans;
        
        Node* left = head;
        Node* right = head;
        
        // move right pointers to the end
        while(right->next != NULL){
            right = right->next;
        }
        
        while (left != NULL && right != NULL && left != right && left->prev != right){
            int sum = left->data + right->data;
            
            if(sum == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if (sum < target){
                left = left->next;
            } else {
                // sum > target
                right = right->prev;
            }
        }
        
        return ans;
        
    }
};