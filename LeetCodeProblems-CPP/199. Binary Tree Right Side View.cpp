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
    map<int, int> right;

    void rightTraverse(TreeNode* root, int level){
        if(root == NULL){
            return;
        }

        if(!right[level]){
            if(root -> val == 0){
                right[level] = 101;
            }else{
                right[level] = root -> val;
            }
        }

        rightTraverse(root -> right, level + 1);
        rightTraverse(root -> left, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        rightTraverse(root, 0);
        vector<int> ans;

        for(auto r : right){
            if(r.second != 101){
                ans.push_back(r.second);
            }else{
                ans.push_back(0);
            }
            
        }

        return ans;
    }
};