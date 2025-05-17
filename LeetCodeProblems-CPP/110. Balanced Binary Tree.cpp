//

class Solution {
public:
    int height(TreeNode* root, vector<bool>& check){
        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root -> left, check);
        int rightHeight = height(root -> right, check);

        check.push_back(abs(leftHeight - rightHeight) <= 1);
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }

        vector<bool> check;
        int n = height(root,check);

        for(auto c : check){
            if(!c){
                return false;
            }
        }

        return true;
       
    }
};

//

class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root -> left);
        int right = height(root -> right);

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);
        bool diff = abs(height(root -> left) - height(root -> right)) <= 1;

        if(left && right && diff){
            return true;
        }else{
            return false;
        }
    }
};