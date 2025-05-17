// using recursion

class Solution {
public:
    void traversal(vector<int>& res, TreeNode* root){

        if(root == NULL){
            return;
        }

        traversal(res, root -> left);
        res.push_back(root -> val);
        traversal(res, root -> right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        traversal(res, root);
        return res;
    }
};

// using stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        stack<TreeNode* > order;
        vector<int> res;
        TreeNode* current = root;

        while(!order.empty() || current){

            while(current){
                order.push(current);
                current = current -> left;
            }

            current = order.top();
            order.pop();
            res.push_back(current -> val);

            current = current -> right;
        }

        return res;
    }
};

// Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        while (root) {
            if(!root -> left){

                result.push_back(root -> val);
                root = root -> right;

            }else{

                TreeNode* leftChild = root -> left;

                while (leftChild->right && leftChild->right != root) {
                    leftChild = leftChild->right;
                }

                if (!leftChild->right) {

                    leftChild->right = root;
                    root = root->left;

                }else{
                
                    leftChild->right = nullptr;
                    result.push_back(root->val);
                    root = root->right;
                    
                }

            }
        }
        return result;
    }
};