// Question Link: 3280. Convert Date to Binary

/*
Approach

We are given a date string in the format "YYYY-MM-DD". The goal is to convert the year, month, and day into their respective binary representations and return them as a single string separated by dashes.
• Use a helper function stringToInt() to extract and convert each part of the date from string to integer.
• Then, convert each of these integers (year, month, day) into binary strings using another helper intToBinary().
• Finally, concatenate the binary strings with '-' in between and return the result.

Complexity

Time complexity:
O(logY+logM+logD)≈O(1)
All parts of the date are fixed-width integers, so the overall complexity is constant.

Space complexity:
O(1)
Only a few strings are used; no additional data structures are required.


*/

class Solution {
public:
    int stringToInt(string date, int start, int end){
        int res = 0;
        for(int idx = start;idx < end; idx++){
            int num = date[idx] - '0';
            if(num == 0 && res == 0){
                continue;
            }
            res = res * 10 + num;
        }
        return res;
    }
    string intToBinary(int num){
        string res = "";
        while(num > 0){
            res = (num % 2 == 0 ? '0' : '1') + res;
            num /= 2;
        }
        return res;
    }
    string convertDateToBinary(string date) {
        int year = stringToInt(date,0,4);
        int month = stringToInt(date,5,7);
        int day = stringToInt(date,8,10);

        return intToBinary(year) + '-' + intToBinary(month) + '-' + intToBinary(day);
    }
};