// Queue
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        int ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            int size = q.size();
            ans = q.front()->val;
            while (size > 0)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
                size--;
            }
        }

        return ans;
    }
};

// DFS
class Solution
{
public:
    int mostDepth = -1;
    int bestVal;
    void dfs(TreeNode *root, int depth)
    {
        if (depth > mostDepth)
        {
            mostDepth = depth;
            bestVal = root->val;
        }

        if (root->left)
        {
            dfs(root->left, depth + 1);
        }
        if (root->right)
        {
            dfs(root->right, depth + 1);
        }
    }
    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return bestVal;
    }
};