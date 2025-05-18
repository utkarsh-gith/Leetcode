/*
Approach 1: Recursion + Brute Force (TLE)
Start from day 0 and index 0, trying all three pass options (1-day, 7-day, 30-day).
	•	Skip travel days already covered by the current pass.
	•	At each step, choose the minimum cost among the three options.
	•	Return the minimum total cost to cover all travel days.
*/

class Solution {
public:
    int costCal(vector<int>& days, vector<int>& costs, int date, int idx){
        if(idx > days.size()){
            return 0;
        }

        int cost = 0;
        if(date >= days[idx]){
            cost += costCal(days, costs, date, idx + 1);
        }else{
            int oneDay = costCal(days, costs, date + 1, idx + 1) + costs[0];
            int sevenDay = costCal(days, costs, date + 7, idx + 1) + costs[1];
            int thirtyDay = costCal(days, costs, date + 30, idx + 1) + costs[2];

            cost = min(oneDay, min(sevenDay, thirtyDay));
        }

        return cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return costCal(days, costs, 0, 0);
    }
};

// OR

class Solution {
public:
    int costCal(vector<int>& days, vector<int>& costs, int idx){
        if(idx >= days.size()){
            return 0;
        }
        
        int i = idx;
        while (i < days.size() && days[i] < days[idx] + 1) i++;
        int one = costs[0] + costCal(days, costs, i);

        i = idx;
        while (i < days.size() && days[i] < days[idx] + 7) i++;
        int seven = costs[1] + costCal(days, costs, i);

        i = idx;
        while (i < days.size() && days[i] < days[idx] + 30) i++;
        int thirty = costs[2] + costCal(days, costs, i);

        return min(one, min(seven, thirty));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return costCal(days, costs, 0);
    }
};

/*
Approach 2: Recursion + Memorisation:
Top-Down DP with Skipping Covered Days
	•	For each travel day at index idx, try buying:
	•	a 1-day pass (covers 1 day),
	•	a 7-day pass (covers next 7 days),
	•	a 30-day pass (covers next 30 days).
	•	Skip all future days already covered by the current pass.
	•	Recursively compute minimum cost from the next uncovered day.
	•	Use memoization (dp[idx]) to avoid recomputation.
*/

class Solution {
public:
    int costCal(vector<int>& days, vector<int>& costs, int idx, vector<int>& dp){
        if(idx >= days.size()){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int i = idx;
        while (i < days.size() && days[i] < days[idx] + 1) i++;
        int one = costs[0] + costCal(days, costs, i, dp);

        i = idx;
        while (i < days.size() && days[i] < days[idx] + 7) i++;
        int seven = costs[1] + costCal(days, costs, i, dp);

        i = idx;
        while (i < days.size() && days[i] < days[idx] + 30) i++;
        int thirty = costs[2] + costCal(days, costs, i, dp);

        dp[idx] = min(one, min(seven, thirty));
        return dp[idx];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return costCal(days, costs, 0, dp);
    }
};

/*
Approach 3: Tabulation
*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        // vector<int> dp(367, INTMAX); O(1) Space Complexity
        dp[n] = 0;

        for(int idx = n - 1;idx >= 0; idx--){
            int one = costs[0] + dp[idx + 1];
    
            int i = idx;
            while (i < days.size() && days[i] < days[idx] + 7) i++;
            int seven = costs[1] + dp[i];

            i = idx;
            while (i < days.size() && days[i] < days[idx] + 30) i++;
            int thirty = costs[2] + dp[i];

            dp[idx] = min(one, min(seven, thirty));
        }

        return dp[0];
    }
};
