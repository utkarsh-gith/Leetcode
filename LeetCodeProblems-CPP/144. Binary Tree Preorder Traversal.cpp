// using recursion

class Solution {
public:
    void traversal(vector<int>& res, TreeNode* root){

        if(root == NULL){
            return;
        }

        res.push_back(root -> val);
        traversal(res, root -> left);
        traversal(res, root -> right);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(res, root);
        return res;
    }
};

// using stack

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        vector<int> res;
        stack<TreeNode* > order;
        order.push(root);

        while(!order.empty()){

            TreeNode* current = order.top();
            order.pop();

            res.push_back(current -> val);

            if(current->right) {
            order.push(current->right);
            }
            if(current->left) {
                order.push(current->left);
            }
            
        }

        return res;
    }
};

// Morris Traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        vector<int> res;
        TreeNode* current = root;

        while(current){

            res.push_back(current -> val);

            if(current -> left == NULL){
                current = current -> right;
            }else{

                TreeNode* temp = current -> left;
                while(temp -> right){
                    temp = temp -> right;
                }

                temp -> right = current -> right;
                temp = current;
                current = current -> left;
                temp -> left = NULL;
            }
        }
        return res;
    }
};
