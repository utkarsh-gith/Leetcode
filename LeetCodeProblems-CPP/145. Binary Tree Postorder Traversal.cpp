//Using Recursion

class Solution {
public:
    void traverse(vector<int>& res, TreeNode* root){
        if(root == NULL){
            return;
        }

        traverse(res, root -> left);
        traverse(res, root -> right);
        res.push_back(root -> val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        traverse(res,root);
        return res;

    }
};

// using stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s;
        TreeNode* current = root;
        TreeNode* lastVisited = NULL;

        while (!s.empty() || current) {
            if (current) {
                s.push(current);
                current = current->left;
            } else {
                TreeNode* node = s.top();
                
                if (node->right && lastVisited != node->right) {
                    current = node->right;
                } else {
                    
                    result.push_back(node->val);
                    lastVisited = node;
                    s.pop();

                }
            }
        }

        return result;
    }
};