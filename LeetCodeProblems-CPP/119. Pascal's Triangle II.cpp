class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> pascal;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
                }
            }
            pascal.push_back(row);
        }
        return pascal[rowIndex];
    }
};

// OR

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> pascal;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(pascal[j - 1] + pascal[j]);
                }
            }
            pascal = row;
            ;
        }
        return pascal;
    }
};

// OR
//  C(n, k) = C(n, k-1) * (n-k+1)/(k)

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        long long res = 1;
        vector<int> temp;
        temp.push_back(res);
        int row = rowIndex + 1;

        for (int col = 1; col < row; col++)
        {
            res = res * (row - col);
            res = res / col;
            temp.push_back(res);
        }
        return temp;
    }
};