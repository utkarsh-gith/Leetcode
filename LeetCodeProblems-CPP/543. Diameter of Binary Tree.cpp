class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (root == NULL) 
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};