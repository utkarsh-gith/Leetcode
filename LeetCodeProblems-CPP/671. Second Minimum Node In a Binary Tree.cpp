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
    int findSecondMinimumValue(TreeNode *root)
    {

        int minVal = root->val;
        long secondMin = LONG_MAX;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->val > minVal && node->val < secondMin)
            {
                secondMin = node->val;
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        return (secondMin == LONG_MAX) ? -1 : (int)secondMin;
    }
};