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
    TreeNode *reverseOddLevels(TreeNode *root)
    {

        queue<TreeNode *> q;
        q.push(root);

        bool change = false;

        while (!q.empty())
        {

            stack<int> st;
            queue<TreeNode *> odd;
            int n = q.size();

            for (int i = 0; i < n; i++)
            {

                TreeNode *temp = q.front();
                q.pop();

                if (change)
                {
                    odd.push(temp);
                    st.push(temp->val);
                }

                if (temp->left)
                {
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if (change)
            {
                while (!st.empty())
                {
                    TreeNode *temp = odd.front();
                    odd.pop();
                    temp->val = st.top();
                    st.pop();
                }
            }
            change = !change;
        }

        return root;
    }
};