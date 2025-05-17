class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        int total_surplus = 0;
        int current_surplus = 0;
        
        int index = 0;
        
        for(int i = 0;i < n;i++){
            
            int balance = gas[i] - cost[i];
            total_surplus += balance;
            current_surplus += balance;
            
            if(current_surplus < 0){
                index = i + 1;
                current_surplus  = 0;
            }
            
        }
        
        return (total_surplus >= 0) ? index : -1;
    }
};