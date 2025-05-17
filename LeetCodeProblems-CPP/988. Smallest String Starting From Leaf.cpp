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
    void helper(TreeNode *root, string &result, string current)
    {
        char c = 'a' + root->val;
        current = c + current;

        if (root->left == NULL && root->right == NULL)
        {
            if (result == "")
            {
                result = current;
            }
            else
            {
                result = min(result, current);
            }
            return;
        }

        if (root->left)
        {
            helper(root->left, result, current);
        }
        if (root->right)
        {
            helper(root->right, result, current);
        }
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string result = "";
        helper(root, result, "");
        return result;
    }
};

// OR Backtracking

class Solution
{
public:
    void helper(TreeNode *root, string &result, string &current)
    {
        char c = 'a' + root->val;
        current = c + current;

        if (root->left == NULL && root->right == NULL)
        {
            if (result == "")
            {
                result = current;
            }
            else
            {
                result = min(result, current);
            }
            current.erase(current.begin());
            return;
        }

        if (root->left)
        {
            helper(root->left, result, current);
        }
        if (root->right)
        {
            helper(root->right, result, current);
        }
        current.erase(current.begin());
    }
    string smallestFromLeaf(TreeNode *root)
    {

        string result = "";
        string s = "";
        helper(root, result, s);
        return result;
    }
};