class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {

        int count = 0;
        map<char, bool> visited;

        for (int i = 0; i < s.length(); i++)
        {

            if (visited[s[i]] == true)
            {
                continue;
            }
            visited[s[i]] = true;

            map<int, bool> unique;
            int j = s.length() - 1;

            while (j > i && s[j] != s[i])
            {
                j--;
            }
            if (j == i)
            {
                continue;
            }

            for (int k = i + 1; k < j; k++)
            {
                if (unique[s[k]] == false)
                {
                    count++;
                    unique[s[k]] = true;
                }
            }
        }

        return count;
    }
};