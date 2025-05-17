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
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        ListNode *left = list1;
        int c = 0;
        while (c < a - 1)
        {
            left = left->next;
            c++;
        }

        ListNode *right = left->next;
        c++;
        while (c < b)
        {
            right = right->next;
            c++;
        }

        left->next = list2;
        while (list2->next)
        {
            list2 = list2->next;
        }
        list2->next = right->next;

        return list1;
    }
};