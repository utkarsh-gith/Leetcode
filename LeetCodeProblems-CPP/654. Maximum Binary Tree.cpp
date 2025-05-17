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
    TreeNode *helper(vector<int> &nums, int start, int end)
    {

        if (start > end)
        {
            return NULL;
        }

        int idx = start;
        for (int i = start + 1; i <= end; i++)
        {
            if (nums[i] > nums[idx])
            {
                idx = i;
            }
        }

        TreeNode *root = new TreeNode(nums[idx]);

        root->left = helper(nums, start, idx - 1);
        root->right = helper(nums, idx + 1, end);

        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};