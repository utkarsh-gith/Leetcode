/*
Approach -
    They have given a rooms 2D vector which stores which room has keys to which other rooms
    This vector is the same as an adjacency list in a graph
    Do a dfs traversal from room 0 to see which rooms can be visited
    Use a visited boolean array to mark the visited rooms
    If any room is not visited return false else return true

    Space Complexity - O(N)
        N -> number of rooms (for visited array)
    Time Complexity - O(N + E)
        N -> number of rooms (visits only once)
        E -> total number of keys (every key once during dfs)
*/

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int node){
        for(int& neighbour : rooms[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                dfs(rooms, visited, neighbour);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        dfs(rooms, visited, 0);

        for(bool visit : visited){
            if(visit == false){
                return false;
            }
        }

        return true;
    }
};