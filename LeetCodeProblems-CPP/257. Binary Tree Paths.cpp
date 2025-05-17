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
class Solution
{
public:
    void treePath(TreeNode *root, vector<string> &paths, string singlePath)
    {

        singlePath += "->" + to_string(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            paths.push_back(singlePath);
            return;
        }
        if (root->left)
        {
            treePath(root->left, paths, singlePath);
        }
        if (root->right)
        {
            treePath(root->right, paths, singlePath);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {

        if (root->left == NULL && root->right == NULL)
        {
            return {to_string(root->val)};
        }

        vector<string> paths;
        string singlePath = to_string(root->val);
        if (root->left)
        {
            treePath(root->left, paths, singlePath);
        }
        if (root->right)
        {
            treePath(root->right, paths, singlePath);
        }
        return paths;
    }
};