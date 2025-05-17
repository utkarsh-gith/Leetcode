class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {

        int i = 0;
        int n = arr.size();
        int count = 0;

        while (i < n)
        {

            if (arr[i] == i)
            {
                count++;
                i++;
                continue;
            }

            int c = arr[i];
            int j = i + 1;
            int req = arr[i] - i;

            while (j < n && req)
            {
                if (arr[j] > c)
                {
                    req = arr[j] - c + req - 1;
                    c = arr[j];
                }
                else
                {
                    req--;
                }
                j++;
            }
            i = j;
            count++;
        }
        return count;
    }
};