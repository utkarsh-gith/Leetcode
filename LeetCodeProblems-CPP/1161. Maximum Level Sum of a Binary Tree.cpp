/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Approach -
    We know we have to find the maximum level sum, so we need a level order traversal
    Level Order Traversal is done best using a queue
    Take three variables:
        maxSum -> initialise to INT_MIN (to store maximum sum)
        maxSumLevel -> initialise to 0 (to store the level of maximum sum)
        level-> initialise to 0 (to store the level that is being traversed)
    Push the root to the queue
    Run the loop until the queue is not empty
        invcrement level to store the actual level
        initialise sum to 0
        run a for loop until the size of queue (size of queue initially before pushing any children)
            add node val to sum
            pop the node
            push its children
        compare sum to maxSum and if sum is greater update maxSum and MaxSumLevel

    Space Complexity - O(n) -> storing the nodes in queue
    Time Complexity - O(n) -> traversing all the nodes
        where n is number of nodes 
*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int maxSumLevel = 0;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int n = q.size();
            int sum = 0;
            level++;

            for(int i = 0;i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                sum += node -> val;
                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
            }

            if(sum > maxSum){
                maxSum = sum;
                maxSumLevel = level;
            }
        }

        return maxSumLevel;
    }
};