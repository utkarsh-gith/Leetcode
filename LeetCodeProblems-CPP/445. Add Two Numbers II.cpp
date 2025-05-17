class Solution {
public:

    ListNode* reverseLL(ListNode* head){

        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* newHead = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }

    ListNode* addNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = l1;
        ListNode* prev = NULL;
        int carry = 0, sum = 0;

        while(l1 && l2){

            int temp = l1->val + l2->val + carry;
            sum = temp % 10;
            carry = temp / 10;

            l1 -> val = sum;

            prev = l1;
            l1 = l1 -> next;
            l2 = l2 -> next; 
        }

        if(!l1){
            if(l2){
                prev -> next = l2;
                l1 = l2;
            }
        }

        while(l1 && carry){
            int temp = l1->val + carry;
            sum = temp % 10;
            carry = temp / 10;

            l1 -> val = sum;

            prev = l1;
            l1 = l1 -> next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev -> next = newNode;
        }

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        l1 = addNumbers(l1, l2);

        l1 = reverseLL(l1);

        return l1;
    }
};