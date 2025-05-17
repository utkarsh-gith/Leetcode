class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c || board[i][col] == c)
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int row)
    {

        while (row < 9)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isSafe(board, row, col, c))
                        {
                            board[row][col] = c;
                            if (solve(board, row))
                            {
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
            row++;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0);
    }
};

// OR

class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c || board[i][col] == c)
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int row, int col)
    {
        if (row == 9)
        {
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9)
        {
            nextRow++;
            nextCol = 0;
        }

        if (board[row][col] != '.')
        {
            return solve(board, nextRow, nextCol);
        }

        for (char c = '1'; c <= '9'; c++)
        {
            if (isSafe(board, row, col, c))
            {
                board[row][col] = c;
                if (solve(board, nextRow, nextCol))
                {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0, 0);
    }
};

// OR

class Solution
{
public:
    vector<vector<bool>> rowCheck;
    vector<vector<bool>> colCheck;
    vector<vector<bool>> sq;

    Solution()
    {
        rowCheck.resize(9, vector<bool>(9, false));
        colCheck.resize(9, vector<bool>(9, false));
        sq.resize(9, vector<bool>(9, false));
    }

    bool isSafe(int row, int col, char c)
    {
        int num = c - '1';
        if (rowCheck[row][num] || colCheck[col][num] || sq[3 * (row / 3) + (col / 3)][num])
        {
            return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, int row, int col)
    {
        if (row == 9)
        {
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9)
        {
            nextRow++;
            nextCol = 0;
        }

        if (board[row][col] != '.')
        {
            return solve(board, nextRow, nextCol);
        }

        for (char c = '1'; c <= '9'; c++)
        {
            if (isSafe(row, col, c))
            {
                int num = c - '1';
                rowCheck[row][num] = true;
                colCheck[col][num] = true;
                sq[3 * (row / 3) + (col / 3)][num] = true;
                board[row][col] = c;
                if (solve(board, nextRow, nextCol))
                {
                    return true;
                }
                rowCheck[row][num] = false;
                colCheck[col][num] = false;
                sq[3 * (row / 3) + (col / 3)][num] = false;
                ;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int c = board[i][j] - '1';
                    rowCheck[i][c] = true;
                    colCheck[j][c] = true;
                    sq[3 * (i / 3) + (j / 3)][c] = true;
                }
            }
        }

        solve(board, 0, 0);
    }
};