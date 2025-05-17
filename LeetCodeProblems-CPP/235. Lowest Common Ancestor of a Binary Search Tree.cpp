class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

// OR

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root == p || root == q)
        {
            return root;
        }
        bool left = p->val < root->val && q->val < root->val;
        bool right = p->val > root->val && q->val > root->val;

        if (!left && !right)
        {
            return root;
        }

        TreeNode *ans = NULL;
        if (left)
        {
            ans = lowestCommonAncestor(root->left, p, q);
        }
        if (right)
        {
            ans = lowestCommonAncestor(root->right, p, q);
        }

        return ans;
    }
};