//using stack

class Solution {
public:
    void reorderList(ListNode* head) {
        
        stack<ListNode* > node;
        ListNode* temp = head;

        while(temp){
            node.push(temp);
            temp = temp -> next;
        }

        if(node.size() <= 2){
            return;
        }

        temp = head;
        while((temp != node.top()) && (temp -> next != node.top())){
            ListNode* curr = node.top();
            node.pop();
            curr -> next = temp -> next;
            temp -> next = curr;
            temp = curr -> next;
        }

        if(temp){
            if(temp == node.top()){
                temp -> next = NULL;
            }else{
                temp -> next -> next = NULL;
            }
        }

    }
};


// find mid, cut right and left , rverse right and add right one to 
// left one by one

