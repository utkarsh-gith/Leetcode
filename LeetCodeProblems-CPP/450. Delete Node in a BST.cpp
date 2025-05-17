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
    TreeNode *minVal(TreeNode *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // 0 Child
            if (root->left == NULL && root->right == NULL)
            {
                delete (root);
                return NULL;
            }

            // 1 Child
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete (root);
                return temp;
            }
            if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete (root);
                return temp;
            }

            // 2 Child
            TreeNode *temp = minVal(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};