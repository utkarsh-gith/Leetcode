// Question Link: https://leetcode.com/problems/reverse-words-in-a-string/

/*
Approach:
- The goal is to reverse the order of words in a string, while:
  1. Removing extra spaces
  2. Ensuring only one space between words
  3. Avoiding leading/trailing spaces

Steps:
1. Start from the end of the string to reverse word order.
2. Skip any trailing spaces using a while loop.
3. Identify a word by finding the start and end indices (non-space characters).
4. Extract the word using `substr` and append it to the result string.
5. Add a single space after each word.
6. After the loop, remove the trailing space from the final result.

Why this works:
- You avoid building a temporary vector or using `stringstream`.
- Only valid words are added, extra spaces are ignored.
- Works in O(n) time and O(n) space (to build the result).

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string reverseWords(string s) {
        string sentence = "";
        int i = s.length() - 1;
        while(i >= 0){
            while(i >= 0 && s[i] == ' '){
                i--;
            }

            if(i < 0){
                break;
            }

            string word = "";
            while(i >= 0 && s[i] != ' '){
                word = s[i] + word;
                i--;
            }

            sentence += word + ' ';

            // int j = i;
            // while(i >= 0 && s[i] != ' '){
            //     i--;
            // }

            // res += s.substr(i + 1, j - i) + ' ';
        }

        sentence.pop_back();

        return sentence;
    }
};