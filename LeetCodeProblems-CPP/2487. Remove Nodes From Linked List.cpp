class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    ListNode *removeNodes(ListNode *head)
    {
        head = reverse(head);
        ListNode *temp = head;
        while (temp != NULL)
        {
            ListNode *node = temp->next;
            while (node && node->val < temp->val)
            {
                node = node->next;
            }
            temp->next = node;
            temp = node;
        }

        head = reverse(head);
        return head;
    }
};

// OR

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        stack<ListNode *> st;

        while (head != NULL)
        {
            while (!st.empty() && head->val > st.top()->val)
            {
                st.pop();
            }
            if (!st.empty())
            {
                st.top()->next = head;
            }
            st.push(head);
            head = head->next;
        }

        while (!st.empty())
        {
            head = st.top();
            st.pop();
        }

        return head;
    }
};