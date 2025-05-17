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
    int sumNode(TreeNode *root, bool d)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (d == true)
            {
                return root->val;
            }
            else
            {
                return 0;
            }
        }

        int sum = 0;
        if (root->left)
        {
            sum += sumNode(root->left, true);
        }
        if (root->right)
        {
            sum += sumNode(root->right, false);
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return sumNode(root->left, true) + sumNode(root->right, false);
    }
};