class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !(head -> next)){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr && curr -> next){

            if(curr -> val == curr -> next -> val){

                int temp = curr -> val;

                while(curr && curr -> val == temp){
                    curr = curr -> next;
                }

                if(prev){
                    prev -> next = curr; 
                }else{
                    head = curr;
                }

            }else{

                prev = curr;
                curr = curr -> next;
                
            }
        }

        return head;
    }
};