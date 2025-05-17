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
    TreeNode *prev = NULL;
    int minVal = INT_MAX;

    void minDiff(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        minDiff(root->left);

        if (prev != NULL)
        {
            minVal = min(minVal, abs(root->val - prev->val));
        }

        prev = root;
        minDiff(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        minDiff(root);
        return minVal;
    }
};