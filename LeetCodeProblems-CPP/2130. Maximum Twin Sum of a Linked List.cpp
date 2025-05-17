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
    int pairSum(ListNode *head)
    {
        stack<ListNode *> st;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast)
        {
            st.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }

        int maxVal = 0;
        while (slow)
        {
            maxVal = max(maxVal, st.top()->val + slow->val);
            st.pop();
            slow = slow->next;
        }

        return maxVal;
    }
};

// OR

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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newNode = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newNode;
    }
    int pairSum(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverse(slow);
        fast = head;
        int maxVal = 0;

        while (slow)
        {
            maxVal = max(maxVal, fast->val + slow->val);
            fast = fast->next;
            slow = slow->next;
        }

        return maxVal;
    }
};