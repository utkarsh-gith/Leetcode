// Floyd Cycle Detection (using slow and fast)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head || !(head -> next)){
            return false;
        }
        if(head == head -> next){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};

// OR

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        map<ListNode* , bool> check;

        if(head == NULL || head -> next == NULL){
            return false;
        }

        while(head != NULL){

            if(check[head]){
                return true;
            }
            check[head] = true;
            head = head -> next;

        }

        return false;
    }
};