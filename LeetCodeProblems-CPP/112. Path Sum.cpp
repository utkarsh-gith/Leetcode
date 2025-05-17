class Solution {
public:
    vector<int> res;

    void dfs(TreeNode* root, int num){
        if(root == NULL){
            return;
        }

        num += root -> val;
        if(root -> left == NULL && root -> right == NULL){
            res.push_back(num);
            return;
        }

        dfs(root -> left, num);
        dfs(root -> right, num);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        dfs(root, 0);

        for(int num : res){
            if(num == targetSum){
                return true;
            }
        }

        return false;
    }
};

//

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL){
            return false;
        }

        if(root -> left == NULL && root -> right == NULL){
            return (root -> val == targetSum);
        }

        int remainingSum = targetSum - root -> val;

        return hasPathSum(root -> left,remainingSum) || hasPathSum(root -> right,remainingSum);
    }
};