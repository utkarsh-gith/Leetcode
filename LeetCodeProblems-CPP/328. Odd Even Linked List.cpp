class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head -> next) || !(head -> next -> next)){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* eprev = head -> next;

        while(odd -> next && even -> next){
            
            odd -> next = odd -> next -> next;
            odd = odd -> next;

            even -> next = even -> next -> next;
            even = even -> next;

        }

        if(even){
            odd -> next = odd -> next -> next;
            even -> next = NULL;
        }

        odd -> next = eprev;

        return head;
    }
};

//OR

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head -> next) || !(head -> next -> next)){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* eprev = even;

        while(even && even -> next){
            
            odd -> next = odd -> next -> next;
            odd = odd -> next;

            even -> next = even -> next -> next;
            even = even -> next;

        }

        odd -> next = eprev;

        return head;
    }
};