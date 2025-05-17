/*
Approach 1: Brute Force with Set (Permutations with Index Check)

1.	Sort the input digits — not strictly necessary for logic, but helps in generating results in order (though set already handles sorting).
2.	Use three nested loops (i, j, k) to pick three different indices:
	•	Ensure i, j, and k are all different.
	•	Ensure the digit at k (units place) is even.
3.	Build the number: digits[i] * 100 + digits[j] * 10 + digits[k].
	•	Check that the number is ≥ 100 (to avoid leading zero).
4.	Insert the number into a set to avoid duplicates.
5.	Finally, return the sorted vector formed from the set.

Time Complexity: O(n³ + U log U), since three nested for loops and U = number of unique 3-digit even numbers ≤ 900
Space Complexity: O(U), where U <= 900 since only 900 number between 100 and 999 
*/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        int n = digits.size();
        sort(digits.begin(), digits.end());

        for(int i = 0;i < n; i++){
            for(int j = 0;j < n; j++){
                if(j != i){
                    for(int k = 0;k < n;k++){
                        if(k != i && k != j && digits[k] % 2 == 0){
                            int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                            if(num >= 100){
                                res.insert(num);
                            }
                        }
                    }
                }
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};


/*
Approach 2: Backtracking with digit frequency array

1.	Create a frequency array freq[10] to count occurrences of each digit from 0 to 9.
2.	Use a recursive function solve(freq, res, num, idx):
    •	num stores the number being built.
    •	idx represents how many digits are still left to add (starts from 3).
3.	At each level, try all digits from 0 to 9 (in order), but:
    •	Skip if digit count is 0 (not available).
    •	Skip 0 as the first digit (to avoid leading zeros).
4.	If 3 digits are placed (idx == 0), check if the number is even.
    •	If yes, add to result.
*/

class Solution {
public:
    void solve(vector<int>& freq, vector<int>& res, int num, int idx){
        if(idx == 0){
            if(num % 2 == 0){
                res.push_back(num);
            }
            return;
        }

        num = num * 10;
        for(int i = 0;i < 10;i++){
            if(num == 0 && i == 0){
                continue;
            }
            if(freq[i] > 0){
                freq[i]--;
                solve(freq, res, num + i, idx - 1);
                freq[i]++;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int& digit : digits){
            freq[digit]++;
        }

        vector<int> res;
        solve(freq, res, 0, 3);
        return res;
    }
};