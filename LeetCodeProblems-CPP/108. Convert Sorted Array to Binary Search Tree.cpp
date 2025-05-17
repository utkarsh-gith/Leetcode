class Solution
{
public:
    TreeNode *buildBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, start, mid - 1);
        root->right = buildBST(nums, mid + 1, end);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }
};