class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head ==  NULL || k <= 1){
            return head;
        }

        ListNode* curr = head;
        int count = 0;

        while(curr != NULL && count < k){
            curr = curr -> next;
            count++;
        }

        if(count < k){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* next = NULL;
        curr = head;
        
        while(curr != NULL && count > 0){
            next =  curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count--;
        }

        if(next != NULL){
            head -> next = reverseKGroup(next, k);
        }

        return prev;
    }
};