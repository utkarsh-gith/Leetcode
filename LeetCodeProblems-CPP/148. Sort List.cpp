//Using map

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        ListNode * temp = head;
        map<int, int> number;

        while(temp != NULL){
            number[temp -> val]++;
            temp = temp -> next;
        }

        temp = head;

        for(auto num : number){
            while(num.second){
                temp -> val = num.first;
                temp = temp -> next;
                num.second--;
            }
        }

        return head;
    }
};

// OR (Merge Sort)

class Solution {
public:

    ListNode* findMid(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){

        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        

        while(left && right){
            if(left -> val <= right -> val){
                temp -> next = left;
                left = left -> next;
            }else{
                temp -> next = right;
                right = right -> next;
            }
            temp = temp -> next;
        }

        if(left){
            temp -> next = left;
        }
        if(right){
            temp -> next = right;
        }

        return ans -> next;

        
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head ->next == NULL){
            return head;
        }

        ListNode* mid = findMid(head);

        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left,right);
        
    }
    ListNode* sortList(ListNode* head) {
        
        return mergeSort(head);
    }
};