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
    int minimumOperations(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        int opr = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            int n = q.size();
            vector<int> check;

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                check.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            for (int i = 0; i < n - 1; i++)
            {
                int minIdx = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (check[minIdx] > check[j])
                    {
                        minIdx = j;
                    }
                }
                if (minIdx != i)
                {
                    opr++;
                    swap(check[minIdx], check[i]);
                }
            }
        }

        return opr;
    }
};