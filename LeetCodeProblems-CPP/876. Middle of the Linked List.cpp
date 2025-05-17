//Count number of nodes and then find second half

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(head -> next == NULL){
            return head;
        }

        int count = 0;
        ListNode* temp = head;

        while(temp != NULL){

            count++;
            temp = temp -> next;
        }

        count /= 2;
        count++;

        for(int i=1;i<count;i++){
            head = head -> next;
        }

        return head;

    }
};

// OR (In single iteration)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(head -> next == NULL){
            return head;
        }

        ListNode* temp = head;

        while(temp -> next != NULL){
            if(temp -> next -> next != NULL){
                temp = temp -> next -> next;
                head = head -> next;
            }
            else{
                head = head -> next;
                break;
            }
        }

        return head;

    }
};