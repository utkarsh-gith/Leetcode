// inoder traversal is always sorted
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &traversal)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> traversal;
        inorder(root, traversal);
        for (int i = 0; i < traversal.size() - 1; i++)
        {
            if (traversal[i] >= traversal[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

// OR

class Solution
{
public:
    bool helper(TreeNode *root, long minR, long maxR)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->val >= maxR || root->val <= minR)
        {
            return false;
        }

        return helper(root->left, minR, root->val) && helper(root->right, root->val, maxR);
    }
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};