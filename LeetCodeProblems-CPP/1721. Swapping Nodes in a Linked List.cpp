class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *temp = head;
        for (int i = 1; i < k; i++)
        {
            temp = temp->next;
        }

        ListNode *fast = temp->next;
        ListNode *slow = head;

        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        swap(temp->val, slow->val);
        return head;
    }
};

// OR -> Big Shit (Overthinking)

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *temp1 = head;
        int n = 1;

        while (temp1 != NULL && temp1->next != NULL)
        {
            temp1 = temp1->next->next;
            n += 2;
        }

        if (temp1 != NULL)
        {
            n++;
        }

        if (k * 2 == n)
        {
            return head;
        }

        temp1 = head;
        ListNode *prev1 = NULL;

        int t = k < n - k ? k : n - k;
        int s = 1;
        while (s < t)
        {
            prev1 = temp1;
            temp1 = temp1->next;
            s++;
        }

        ListNode *temp2 = temp1;
        ListNode *prev2 = prev1;

        t = k > n - k ? k : n - k;
        while (s < t)
        {
            prev2 = temp2;
            temp2 = temp2->next;
            s++;
        }

        if (head == temp1)
        {
            prev2->next = temp1;
            temp2->next = temp1->next;
            temp1->next = NULL;
            return temp2;
        }

        prev1->next = temp2;
        prev2->next = temp1;
        prev1 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = prev1;

        return head;
    }
};