// this one pair column to row,val
// we then sort values in each col based on row(less row, val first)
// push to vector

class Solution {
public:

    void tarversal(TreeNode* root, int col, int row, map<int, vector<pair<int, int>>>& nodes){

        if(root == NULL){
            return;
        }

        nodes[col].push_back({row, root -> val});

        if(root -> left){
            tarversal(root -> left, col - 1, row + 1, nodes);
        }
        if(root -> right){
            tarversal(root -> right, col + 1, row + 1, nodes);
        }

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        vector<vector<int>> result;
        map<int, vector<pair<int, int>>> nodes;

        tarversal(root, 0, 0, nodes);

        for(auto [col, value] : nodes){
            sort(value.begin(),value.end());
            vector<int> ans;
            for(auto [row, val]: value){
                ans.push_back(val);
            }
            result.push_back(ans);
        }

        return result;
    }
};

// using queue

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        map<int, map<int,vector<int>>> node;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> res;
        q.push({root, {0 ,0}});

        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp = q.front();
            q.pop();

            TreeNode* n = temp.first;
            int col = temp.second.first;
            int row = temp.second.second;

            node[col][row].push_back(n -> val);

            if(n -> left){
                q.push({n -> left, {col - 1 ,row + 1}});
            }
            if(n -> right){
                q.push({n -> right, {col + 1 ,row + 1}});
            }
        }

        for(auto i : node){
            vector<int> ans;
            for(auto [j, val] : i.second){
                sort(val.begin(),val.end());
                for(auto k : val){
                    ans.push_back(k);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};

// this will give vertical order traversal but wont be sorted level wise
// idk why it has to be sorted (ig to make the problem hard)

class Solution {
public:

    void tarversal(TreeNode* root, int index, map<int,vector<int>> &nodes){

        if(root == NULL){
            return;
        }

        nodes[index].push_back(root -> val);

        if(root -> left){
            tarversal(root -> left, index - 1, nodes);
        }
        if(root -> right){
            tarversal(root -> right, index + 1, nodes);
        }

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        vector<vector<int>> result;
        map<int,vector<int>> nodes;

        tarversal(root, 0, nodes);

        for(auto n : nodes){
            sort(n.second.begin(),n.second.end());
            result.push_back(n.second);
        }

        return result;
    }
};