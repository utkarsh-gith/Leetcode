class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        
        queue<TreeNode* > node;
        queue<int> value;
        int sum = 0;

        node.push(root);
        value.push(0);

        while(!node.empty()){

            TreeNode* tempNode = node.front();
            node.pop();
            
            int tempVal = value.front();
            value.pop();

            if(tempNode -> left){
                node.push(tempNode -> left);
                value.push(tempVal * 2 + tempNode -> val);
            }
            if(tempNode -> right){
                node.push(tempNode -> right);
                value.push(tempVal * 2 + tempNode -> val);
            }
            if(tempNode -> left == NULL && tempNode -> right == NULL){
                sum += tempVal * 2 + tempNode -> val;
            }
        }

        while(!value.empty()){
            sum += value.front();
            value.pop();
        }

        return sum;
        
    }
};

// using dfs

class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* root,int num){

        if(root == NULL){
            return;
        }

        num = 2 * num + root -> val;
        if(root -> left == NULL && root -> right == NULL){
            sum += num;
            return;
        }

        dfs(root -> left, num);
        dfs(root -> right, num);

    }
    int sumRootToLeaf(TreeNode* root) {
        
        dfs(root, 0);
        return sum;
    }
};