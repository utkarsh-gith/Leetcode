//Tricky : just move the elements

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* prev = NULL;
        while(node -> next != NULL){
            
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
            
        }
        
        prev -> next = NULL;
        delete(node);
        
    }
};