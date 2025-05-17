class Solution
{
public:
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int startIndex, int endIndex, int &index, unordered_map<int, int> &inorderMap)
    {
        if (index >= preorder.size() || startIndex > endIndex)
        {
            return nullptr;
        }

        int rootVal = preorder[index];
        TreeNode *root = new TreeNode(rootVal);

        int idx = inorderMap[rootVal];

        index++;

        root->left = buildTreeHelper(preorder, inorder, startIndex, idx - 1, index, inorderMap);
        root->right = buildTreeHelper(preorder, inorder, idx + 1, endIndex, index, inorderMap);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderMap[inorder[i]] = i;
        }

        int index = 0;
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, index, inorderMap);
    }
};

// OR

class Solution
{
public:
    TreeNode *tree(vector<int> &preorder, vector<int> &inorder, int startIndex, int endIndex, int &index, int n)
    {

        if (index >= n || startIndex > endIndex)
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
        index++;
        root->left = tree(preorder, inorder, startIndex, idx - 1, index, n);
        root->right = tree(preorder, inorder, idx + 1, endIndex, index, n);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        int index = 0;
        return tree(preorder, inorder, 0, preorder.size() - 1, index, preorder.size());
    }
};
