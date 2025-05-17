class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        for(int i = 0;i < arr.size();i++){
            for(int j = 0;j < arr.size();j++){
                if(i != j && (arr[i] * 2 == arr[j] || arr[j] * 2 == arr[i])){
                    return true;
                }
            }
        }
        return false;
    }
};

// OR

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        map<int,bool> exists;

        for(int a : arr){
            if(exists[a * 2] == true){
                return true;
            }
            if((a % 2 == 0) &&(exists[a / 2] == true)){
                return true;
            }
            exists[a] = true;
        }

        return false;
    }
};