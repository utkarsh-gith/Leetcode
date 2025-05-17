class Solution
{
public:
    vector<int> minOperations(string boxes)
    {

        vector<int> result;
        int totalMoves = 0;
        int left = 0;
        int right = 0;
        int current = boxes[0] == '1' ? 1 : 0;

        for (int i = 1; i < boxes.length(); i++)
        {
            if (boxes[i] == '1')
            {
                totalMoves += i;
                right++;
            }
        }
        result.push_back(totalMoves);

        for (int i = 1; i < boxes.size(); i++)
        {
            left += current;
            current = boxes[i] == '1' ? 1 : 0;
            right -= current;
            totalMoves += left - right - current;
            result.push_back(totalMoves);
        }

        return result;
    }
};

// OR

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> ans;
        for (int i = 0; i < boxes.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < boxes.size(); j++)
            {
                if (boxes[j] == '1')
                {
                    count += abs(i - j);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};