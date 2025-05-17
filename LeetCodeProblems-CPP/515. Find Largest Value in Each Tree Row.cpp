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
    vector<int> largestValues(TreeNode *root)
    {

        if (root == NULL)
        {
            return {};
        }

        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            int n = q.size();
            int num = INT_MIN;

            for (int i = 0; i < n; i++)
            {

                TreeNode *temp = q.front();
                q.pop();

                num = max(num, temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            res.push_back(num);
        }

        return res;
    }
};