//Idea - traverse one list and set map value to true, the check if map value true and other one false the push_back

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inter;
        map<int,bool> v1,v2;
        for(int i=0;i<nums1.size();i++){
            v1[nums1[i]] = true;
        }
        for(int i=0;i<nums2.size();i++){
            if(v1[nums2[i]] == true && v2[nums2[i]] == false){
                inter.push_back(nums2[i]);
                v2[nums2[i]] = true;
            }
        }
        return inter;
    }
};