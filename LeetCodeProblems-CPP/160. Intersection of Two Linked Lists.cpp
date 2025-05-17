// Not good Approach
// Marking all elements of the LL to -ve and checcking is -ve present
// works only if elements are greater than 0

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL){
            return headA;
        }
        if(headB == NULL){
            return headB;
        }

        ListNode* node;
        node = NULL;

        ListNode* temp = headA;

        while(temp != NULL){
            temp -> val = - (temp -> val);
            temp = temp -> next;
        }

        temp = headB;

        while(temp != NULL){
            if(temp -> val < 0){
                node = temp;
                break;
            }
            temp = temp -> next;
        }

        temp = headA;

        while(temp != NULL){
            temp -> val = - (temp -> val);
            temp = temp -> next;
        }

        return node;

    }
};

// OR (here both keep traversing untill intersection found or both NULL)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode* a = headA;
        ListNode* b = headB;



        while (a != b) {

            // OR
            // a = (a == NULL) ? headA : a->next;
            // b = (b == NULL) ? headB : b->next;

            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
            
        }


        return a;
    
    }
};