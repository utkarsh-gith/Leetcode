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
    pair<int, int> solve(TreeNode *root)
    {

        pair<int, int> curr = {0, 0};
        if (root == NULL)
        {
            return curr;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        curr.first = root->val + left.second + right.second;
        curr.second = max(left.first, left.second) + max(right.first, right.second);

        return curr;
    }

    int rob(TreeNode *root)
    {

        pair<int, int> maxSum = solve(root);
        return max(maxSum.first, maxSum.second);
    }
};