class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int , bool> check;

        for(auto num : nums){
            if(check[num] == true){
                return true;
            }
            check[num] = true;
        }

        return false;
    }
};