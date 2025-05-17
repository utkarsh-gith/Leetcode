// using stack

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head -> next == NULL){
            return true;
        }
        
        stack<int> s1;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL && fast -> next != NULL){
            s1.push(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(fast != NULL){
            slow = slow -> next;
        }

        while(slow != NULL){
            
            if(s1.top() != slow -> val){
                return false;
            }
            s1.pop();
            slow = slow -> next;

        }

        return 1;

    }
};

// OR reversing list from half

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        
        ListNode* current = head;
        ListNode* forward = current -> next;
        ListNode* prev = NULL;

        while(current != NULL){

            current -> next = prev;

            prev = current;
            current = forward;
            if(forward != NULL){
                forward = forward -> next;
            }

        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head -> next == NULL){
            return true;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast -> next){

            slow = slow -> next;
            fast = fast -> next -> next;
        }

        fast = reverseList(slow);

        while(fast){
            if(fast -> val != head -> val){
                return false;
            }
            fast = fast -> next;
            head = head -> next;
        }

        return true;
        
    }
};

// OR (will not work on leetcode due to large testcase and runtime error)

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        int sum1 = 0, sum2 = 0;
        int c = 0;

        while(head != NULL){

            sum1 = sum1 * 10 + head -> val;
            sum2 = sum2 + head -> val * pow(10,c++);
            head = head -> next;

        }

        return sum1 == sum2 ? 1 : 0;
        
    }
};