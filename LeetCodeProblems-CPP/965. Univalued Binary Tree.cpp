class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        bool left = true;
        bool right = true;

        if(root -> left){
            left = (root -> val == root -> left -> val);
        }
        if(root -> right){
            right = (root -> val == root -> right -> val);
        }

        return left && right && isUnivalTree(root -> left) && isUnivalTree(root -> right);
        
    }
};