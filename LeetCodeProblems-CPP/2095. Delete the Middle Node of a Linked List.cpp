class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head == NULL || head -> next == NULL){
            head = head -> next;
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* vslow = NULL;

        while(fast && fast -> next){
            fast = fast -> next -> next;
            vslow = slow;
            slow = slow -> next;
        }

        vslow -> next = slow -> next;
        delete(slow);

        return head;

        
    }
};