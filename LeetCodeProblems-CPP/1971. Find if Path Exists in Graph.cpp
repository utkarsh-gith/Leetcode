//BFS Traversal

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination){
            return true;
        }

        vector<vector<int>> adjList(n);
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(source);

        vector<bool> visited(n, false);
        visited[source] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int& neighbour : adjList[node]){
                if(neighbour == destination){
                    return true;
                }
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
};