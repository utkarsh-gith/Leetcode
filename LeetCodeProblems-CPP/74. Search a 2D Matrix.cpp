// Idea: Sorted 2D Matrix, So we can apply Binary search, first find the row where the element can be, the the element in that row
// Time Complexity: O(log(m * n))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int row = a.size() - 1;
        int col = a[0].size() - 1;
        int l = 0, h = row, m, n;
        while (l <= h) {
            m = (l + h) / 2;
            if (a[m][0] <= target && a[m][col] >= target) {
                l = 0;
                h = col;
                while (l <= h) {
                    n = (l + h) / 2;
                    if (a[m][n] == target)
                        return 1;
                    else if (a[m][n] > target)
                        h = n - 1;
                    else
                        l = n + 1;
                }
            } else if (a[m][col] > target)
                h = m - 1;
            else
                l = m + 1;
        }

        return 0;
    }
};
