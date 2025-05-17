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
    string preOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }

        string leftAns = preOrder(root->left);
        string rightAns = preOrder(root->right);

        string res = to_string(root->val);
        if (leftAns.empty() && rightAns.empty())
        {
            return res;
        }

        res += '(' + leftAns + ')';
        if (rightAns.length() != 0)
        {
            res += '(' + rightAns + ')';
        }

        return res;
    }
    string tree2str(TreeNode *root)
    {
        return preOrder(root);
    }
};