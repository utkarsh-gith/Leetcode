class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if (k > s.length())
        {
            return false;
        }

        if (k == s.length())
        {
            return true;
        }

        vector<int> count(26, 0);
        int oddCount = 0;

        for (char c : s)
        {
            count[c - 'a']++;
            if (count[c - 'a'] % 2 == 1)
            {
                oddCount++;
            }
            else
            {
                oddCount--;
            }
        }

        if (oddCount > k)
        {
            return false;
        }

        return true;
    }
};