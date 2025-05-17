class Solution
{
public:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        int n1 = str1.length();
        int n2 = str2.length();

        for (int i = 0; i < n1; i++)
        {
            if (str1[i] != str2[i] || str1[i] != str2[n2 - n1 + i])
            {
                return false;
            }
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string> &words)
    {

        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string s1 = words[i];
            for (int j = i + 1; j < words.size(); j++)
            {
                string s2 = words[j];
                if (s1.length() <= s2.length() && isPrefixAndSuffix(s1, s2))
                {
                    count++;
                }
            }
        }
        return count;
    }
};