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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;
                
        if(root == NULL){
            return result;
        }

        queue<TreeNode*> traverse;

        traverse.push(root);

        while(!traverse.empty()){

            int size = traverse.size();
            vector<int> level;

            for(int i = 0;i < size; i++){

                TreeNode* temp = traverse.front();
                traverse.pop();

                level.push_back(temp -> val);

                if(temp -> left){
                    traverse.push(temp -> left);
                }
                if(temp -> right){
                    traverse.push(temp -> right);
                }

            }

            result.push_back(level);

        }

        return result;
    }
};