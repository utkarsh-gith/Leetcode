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
class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, int targetSum, long long currentSum){

        if(root == NULL){
            return;
        }

        currentSum += root ->val;

        if(currentSum == targetSum){
            count++;
        }

        dfs(root -> left, targetSum, currentSum);
        dfs(root -> right, targetSum, currentSum);
    
    }
    int pathSum(TreeNode* root, int targetSum) {

        if (root == NULL) {
            return 0;
        }

        dfs(root, targetSum, 0);

        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);

        return count;
    }
};