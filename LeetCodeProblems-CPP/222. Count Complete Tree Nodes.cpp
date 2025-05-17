class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }

        queue<TreeNode* > tree;
        int count = 1;
        tree.push(root);

        while(!tree.empty()){

            TreeNode* temp = tree.front();
            tree.pop();

            if(temp -> right){
                count += 2;
                tree.push(temp -> left);
                tree.push(temp -> right);
            }
            else if(temp -> left){
                count++;
                tree.push(temp -> left);
            }
        }

        return count;
    }
};

// or

class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};