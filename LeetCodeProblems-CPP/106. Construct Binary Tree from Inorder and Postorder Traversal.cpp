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
    TreeNode *tree(vector<int> &preorder, vector<int> &inorder, int startIndex, int endIndex, int &index, int n)
    {

        if (index < 0 || startIndex > endIndex)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[index]);
        int idx = startIndex;
        while (idx < endIndex && inorder[idx] != preorder[index])
        {
            idx++;
        }
        if (idx > endIndex)
        {
            idx = -1;
        }
        index--;
        root->right = tree(preorder, inorder, idx + 1, endIndex, index, n);
        root->left = tree(preorder, inorder, startIndex, idx - 1, index, n);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = inorder.size();
        int index = n - 1;
        return tree(postorder, inorder, 0, n - 1, index, n);
    }
};

// OR

class Solution
{
public:
    TreeNode *tree(vector<int> &preorder, vector<int> &inorder, int startIndex, int endIndex, int &index, int n, map<int, int> &node)
    {

        if (index < 0 || startIndex > endIndex)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[index]);
        int idx = node[preorder[index]];
        index--;
        root->right = tree(preorder, inorder, idx + 1, endIndex, index, n, node);
        root->left = tree(preorder, inorder, startIndex, idx - 1, index, n, node);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = inorder.size();
        int index = n - 1;

        map<int, int> node;
        for (int i = 0; i < n; i++)
        {
            node[inorder[i]] = i;
        }
        return tree(postorder, inorder, 0, n - 1, index, n, node);
    }
};