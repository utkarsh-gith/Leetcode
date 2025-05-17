class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !(head -> next)){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next ;
                }
                return slow;
            }
        }

        return NULL;

    }
};

// In the "tortoise and hare" algorithm for detecting loops in a linked list,
// when the slow pointer (tortoise) reaches the starting point of the loop, 
// the fast pointer (hare) is positioned at a point that is twice the distance
// travelled by the slow pointer. This is because the hare moves at double the 
// speed of the tortoise.

// If slow has travelled distance L1 then fast has travelled 2 x L1. Now that 
// slow and fast have entered the loop, the distance fast will have to cover 
// to catch up to slow is the total length of loop minus L1. Let this distance 
// be d.

//     Distance travelled by slow = L1
//     Distance travelled by fast = 2 * L1
//     otal length of loop = L1 + d
                        
// In this configuration, the fast pointer advances toward the slow pointer 
// with two jumps per step, while the slow pointer moves away with one jump 
// per step. As a result, the gap between them decreases by 1 with each step. 
// Given that the initial gap is d, it takes exactly d steps for them to meet.

//     Total length of loop = L1 + d
//     Distance between slow and fast= d
                        

// During these d steps, the slow pointer effectively travels d steps from 
// the starting point within the loop and fast travels 2 x d and they meet 
// a specific point. Based on our previous calculations, the total length 
// of the loop is L1 + d. And since the distance covered by the slow pointer 
// within the loop is d, the remaining distance within the loop is equal to L1.

// Therefore, it is proven that the distance between the starting point 
// of the loop and the point where the two pointers meet is indeed equal 
// to the distance between the starting point and head of the linked list.