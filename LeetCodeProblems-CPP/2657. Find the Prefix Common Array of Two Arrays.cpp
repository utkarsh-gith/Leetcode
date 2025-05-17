class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {

        map<int, int> count;
        for (int i = 0; i < A.size(); i++)
        {
            int a = A[i];
            int b = B[i];
            A[i] = 0;

            count[a]++;
            count[b]++;
            if (count[a] == 2 && count[b] == 2)
            {
                if (a == b)
                {
                    A[i] = 1;
                }
                else
                {
                    A[i] = 2;
                }
            }
            else if (count[a] == 2 || count[b] == 2)
            {
                A[i] = 1;
            }

            if (i > 0)
            {
                A[i] += A[i - 1];
            }
        }

        return A;
    }
};

// OR

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {

        int n = A.size();
        vector<int> freq(n + 1, 0), res(n);
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {

            freq[A[i]]++;
            if (freq[A[i]] == 2)
                cnt++;

            freq[B[i]]++;
            if (freq[B[i]] == 2)
                cnt++;

            res[i] = cnt;
        }

        return res;
    }
};