class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !(head -> next)){
            return head;
        }
        
        int count = 1;
        ListNode* last = head;

        while(last -> next){
            count++;
            last = last -> next;
        }

        k = k % count;

        if(!k){
            return head;
        }

        ListNode* temp = head;
        for(int i = 1;i < count - k;i++){
            temp = temp -> next;
        }
        
        last -> next = head;
        head = temp -> next;
        temp -> next = NULL;

        return head;

    }
};