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
    void sumToLeaf(TreeNode* root, int& sum, int pathSum){

        if(root == NULL){
            return;
        }

        pathSum = pathSum * 10 + root ->val;
        if(root -> left == NULL && root -> right == NULL){
            sum += pathSum;
            return;
        }

        if(root -> left){
            sumToLeaf(root -> left, sum, pathSum);
        }
        if(root -> right){
            sumToLeaf(root -> right, sum, pathSum);
        }

    }
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        int pathSum = 0;

        sumToLeaf(root, sum, pathSum);
        return sum;
    }
};