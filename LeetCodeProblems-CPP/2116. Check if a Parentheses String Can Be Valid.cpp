class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        if (s.length() % 2 == 1)
        {
            return false;
        }

        int open = 0, close = 0, unlocked = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (locked[i] == '0')
            {
                unlocked++;
            }
            else if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if (unlocked < (close - open))
            {
                return false;
            }
        }

        open = close = unlocked = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (locked[i] == '0')
            {
                unlocked++;
            }
            else if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if (unlocked < (open - close))
            {
                return false;
            }
        }

        return true;
    }
};