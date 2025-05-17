class Solution {
public:
    void similarTree(TreeNode* root, vector<int>& res){

        if(root == NULL){
            return;
        }

        if(root -> left == NULL && root -> right == NULL){
            res.push_back(root -> val);
            return;
        }
        
        similarTree(root -> left,res);
        similarTree(root -> right,res);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> res1;
        vector<int> res2;
        
        similarTree(root1,res1);
        similarTree(root2,res2);

        return res1 == res2;

    }
};