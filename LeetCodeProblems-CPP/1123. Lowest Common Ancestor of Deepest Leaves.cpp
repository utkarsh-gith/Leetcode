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
    pair<TreeNode *, int> findLCA(TreeNode *root)
    {
        if (root == NULL)
        {
            return {NULL, 0};
        }

        pair<TreeNode *, int> nodeLeft = findLCA(root->left);
        pair<TreeNode *, int> nodeRight = findLCA(root->right);

        if (nodeLeft.first == NULL && nodeRight.first == NULL)
        {
            return {root, 1};
        }
        else if (nodeLeft.second > nodeRight.second)
        {
            return {nodeLeft.first, nodeLeft.second + 1};
        }
        else if (nodeLeft.second < nodeRight.second)
        {
            return {nodeRight.first, nodeRight.second + 1};
        }
        else
        {
            return {root, nodeLeft.second + 1};
        }
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        pair<TreeNode *, int> node = findLCA(root);
        return node.first;
    }
};