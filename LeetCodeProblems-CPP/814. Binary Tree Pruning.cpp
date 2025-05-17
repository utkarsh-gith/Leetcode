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
    bool pruning(TreeNode *root)
    {

        if (root == NULL)
        {
            return false;
        }

        bool leftAns = pruning(root->left);
        bool rightAns = pruning(root->right);

        if (leftAns == false)
        {
            root->left = NULL;
        }
        if (rightAns == false)
        {
            root->right = NULL;
        }

        return leftAns || root->val || rightAns;
    }
    TreeNode *pruneTree(TreeNode *root)
    {

        bool ans = pruning(root);

        if (ans == false)
        {
            root = NULL;
        }

        return root;
    }
};