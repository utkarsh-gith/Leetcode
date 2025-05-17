class Solution {
public:
    int count = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root == NULL){
            return 0;
        }

        if(root -> val >= low && root -> val <= high){
            return root -> val + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
        }
        
        return rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
    }
};