class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {

        unordered_map<int, int> freq;
        int maxFreq = 0;
        int count = 0;

        for (int num : nums)
        {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        for (auto f : freq)
        {
            if (f.second == maxFreq)
            {
                count += maxFreq;
            }
        }

        return count;
    }
};

// OR

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {

        int n = nums.size();
        int count = 0;
        int maxFreq = 0;

        for (int i = 0; i < n; i++)
        {

            int freq = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    freq++;
                }
            }

            if (freq > maxFreq)
            {
                count = freq;
                maxFreq = freq;
            }
            else if (freq == maxFreq)
            {
                count += freq;
            }
        }

        return count;
    }
};