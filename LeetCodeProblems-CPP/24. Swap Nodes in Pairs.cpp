class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !(head -> next)){
            return head;
        }

        ListNode* curr = head -> next;
        ListNode* next = curr -> next;

        curr -> next = head;

        head -> next = swapPairs(next);

        return curr;
    }
};