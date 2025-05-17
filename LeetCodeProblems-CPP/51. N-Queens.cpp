class Solution
{
public:
    vector<string> addSoln(vector<vector<int>> &queen)
    {
        vector<string> ans;
        for (auto qun : queen)
        {
            string temp = "";
            for (auto q : qun)
            {
                if (q)
                {
                    temp += "Q";
                }
                else
                {
                    temp += ".";
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

    bool isSafe(vector<vector<int>> &queen, int row, int col, int n)
    {
        int x = row;
        int y = col;

        while (y >= 0)
        {
            if (queen[x][y])
            {
                return false;
            }
            y--;
        }

        y = col;
        while (y >= 0 && x >= 0)
        {
            if (queen[x][y])
            {
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;
        while (x < n && y >= 0)
        {
            if (queen[x][y])
            {
                return false;
            }
            x++;
            y--;
        }

        return true;
    }

    void helper(vector<vector<string>> &res, vector<vector<int>> &queen, int idx, int n)
    {
        if (idx == n)
        {
            res.push_back(addSoln(queen));
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(queen, row, idx, n))
            {
                queen[row][idx] = 1;
                helper(res, queen, idx + 1, n);
                queen[row][idx] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<vector<int>> queen(n, vector<int>(n, 0));
        helper(res, queen, 0, n);
        return res;
    }
};

// Did not understand the below solution
class Solution
{
public:
    int boardSize;                    // Size of the board (n x n)
    vector<vector<string>> solutions; // Stores all valid solutions

    void dfs(int rowMask, int leftDiag, int rightDiag, int currentRow, vector<string> &board)
    {
        // Base Case: If all rows are processed, add the board to the solutions
        if (currentRow == boardSize)
        {
            solutions.push_back(board);
            return;
        }

        string currentRowStr(boardSize, '.'); // Empty row template

        // Try placing a queen in each column
        for (int col = 0; col < boardSize; col++)
        {
            int bitMask = 1 << col; // Mark the column as a bit

            // Check if the column or diagonals are under attack
            if (rowMask & bitMask || leftDiag & bitMask || rightDiag & bitMask)
            {
                continue;
            }

            // Place the queen
            currentRowStr[col] = 'Q';
            board.push_back(currentRowStr);

            // Recurse to the next row
            dfs(
                rowMask | bitMask,          // Mark the column
                (leftDiag | bitMask) << 1,  // Mark the left diagonal
                (rightDiag | bitMask) >> 1, // Mark the right diagonal
                currentRow + 1,             // Move to the next row
                board);

            // Backtrack: Remove the queen and reset the row
            currentRowStr[col] = '.';
            board.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        boardSize = n;
        solutions.clear();      // Reset solutions for new problem size
        vector<string> board;   // Temporary board for backtracking
        dfs(0, 0, 0, 0, board); // Start the DFS
        return solutions;       // Return all solutions
    }
};