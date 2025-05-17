// Reservoir Sampling

// OR

class Solution
{
public:
    ListNode *head;
    int n;

    Solution(ListNode *head)
    {
        this->head = head;
        ListNode *temp = head;
        n = 0;
        while (temp)
        {
            temp = temp->next;
            n++;
        }
    }

    int getRandom()
    {
        ListNode *temp = head;
        int index = rand() % n;
        while (index > 0)
        {
            temp = temp->next;
            index--;
        }
        return temp->val;
    }
};