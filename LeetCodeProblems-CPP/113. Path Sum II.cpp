class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* root, int targetSum, vector<int> path){

        if(root == NULL){
            return;
        }

        path.push_back(root -> val);
        int remainingSum = targetSum - root -> val;

        if(root -> left == NULL && root -> right == NULL){
            if(remainingSum == 0){
                result.push_back(path);
            }
            return;
        }

        dfs(root -> left, remainingSum, path);
        dfs(root -> right, remainingSum, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> path;
        dfs(root, targetSum, path);

        return result;
    }
};

//