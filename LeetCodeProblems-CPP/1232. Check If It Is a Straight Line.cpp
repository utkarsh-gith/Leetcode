class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        if (n == 2) {
            return true;
        }

        int dx1 = coordinates[1][0] - coordinates[0][0];
        int dy1 = coordinates[1][1] - coordinates[0][1];

        for (int i = 1; i < n - 1; i++) {

            int dx2 = coordinates[i + 1][0] - coordinates[i][0];
            int dy2 = coordinates[i + 1][1] - coordinates[i][1];

            if (dy1 * dx2 != dy2 * dx1) {
                return false;
            }
            
        }

        return true;
    }
};