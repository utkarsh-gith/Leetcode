/*
Approach:
- `isConnected` is a 2D vector that represents an adjacency matrix of a graph.
- Each `1` in `isConnected[i][j]` means city `i` is directly connected to city `j`.
- Do a DFS traversal starting from every unvisited city.
- The number of DFS calls equals the number of "provinces" (connected components).

Time Complexity: O(N²)
- We iterate over the entire adjacency matrix (size N x N) in worst case.

Space Complexity: O(N)
- For the `visited` array and recursive call stack in DFS.
*/

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node){
        for(int i = 0;i < isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;

        vector<bool> visited(n, false);

        for(int i = 0;i < n; i++){
            if(!visited[i]){
                provinces++;
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }

        return provinces;
    }
};