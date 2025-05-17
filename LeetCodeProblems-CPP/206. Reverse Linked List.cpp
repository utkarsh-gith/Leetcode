/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Approach 1 - Iterative
    We have to reverse a LL so we have to reverse the connections
    If there is no node or a single node then the reverse is same as the given
    If there are two or more nodes, then we need three pointers:
        prevNode that is initialised to NULL
        currNode that is initialised to head
        nextNode that is initialied to head -> next
    Run a loop until currNode is valid
        connect currNode to prevNode
        change prevNode to currNode
        change currNode to nextNode
        change nextNode to nextNode -> next (Only until nextNode is valid because at last iteration nextNode will br NULL)

    Space Complexity - O(1)
    Time Complexity - O(n)
        where n is number of nodes 
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        ListNode* nextNode = head -> next;

        while(currNode){
            currNode -> next = prevNode;
            
            prevNode = currNode;
            currNode = nextNode;
            if(nextNode){
                nextNode = nextNode -> next;   
            }
        }

        return prevNode;
    }
};

/*
Approach 2 - Recursive
    If there is no node or a single node then the reverse is same as the given
    So the based condition would be if head is NULL or head -> next is NULL
    If not the recursive call the function to get the newHead (will return the last node)
    Then connect head->next (node next to head) to head (head -> next -> next = head) and change head -> next to NULL
    return the newHead

    Space Complexity - O(n) -> Every recursive call adds a new frame to the call stack
    Time Complexity - O(n) -> The function visits each node exactly once
        where n is number of nodes 
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* newHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }
};