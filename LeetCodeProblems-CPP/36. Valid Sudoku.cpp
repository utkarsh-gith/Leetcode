// using hash map
class Solution
{
public:
    int findSq(int i, int j)
    {
        int sq;
        if (i < 3)
        {
            sq = 0;
        }
        else if (i < 6)
        {
            sq = 3;
        }
        else
        {
            sq = 6;
        }
        if (j < 3)
        {
            sq += 0;
        }
        else if (j < 6)
        {
            sq += 1;
        }
        else
        {
            sq += 2;
        }
        return sq;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {

        vector<map<char, bool>> row(9);
        vector<map<char, bool>> col(9);
        vector<map<char, bool>> sq(9);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c == '.')
                {
                    continue;
                }
                int square = findSq(i, j);
                if (row[i].find(c) != row[i].end() || col[j].find(c) != col[j].end() || sq[square].find(c) != sq[square].end())
                {
                    return false;
                }
                row[i][c] = true;
                col[j][c] = true;
                sq[square][c] = true;
            }
        }
        return true;
    }
};

// Or using just vectors

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sq(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int num = board[i][j] - '1';
                int squ = (i / 3) * 3 + (j / 3);
                if (row[i][num] || col[j][num] || sq[squ][num])
                {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sq[squ][num] = true;
            }
        }

        return true;
    }
};

// OR with O(1) space

class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c) // checks within column
                return false;
            if (board[row][i] == c) // checks within row
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // checks within submatrix
                return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    char curr_char = board[i][j];
                    board[i][j] = '.';
                    if (!isValid(board, i, j, curr_char))
                    {
                        return false;
                    }
                    board[i][j] = curr_char;
                }
            }
        }
        return true;
    }
};