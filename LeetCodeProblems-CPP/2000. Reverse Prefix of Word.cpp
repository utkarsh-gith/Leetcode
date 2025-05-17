// Idea: while the character is not found in the string keep reversing and add it the characters to another string,
//       then at last add the remaing string to the reversed string


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int x=word.size(),i=0;
        string rev;
        rev.clear();
        while(i<x)
        {
            if(word[i]!=ch){
                rev = word[i] + rev;
                i++;
            }
            else
                break;
        }
        if(i>=x)
            return word;
        else
            rev = word[i++] + rev;
        while(i<x)
        {
            rev += word[i];
            i++;
        }
        return rev;
    }
};

// OR

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.length();
        int i = 0;

        while(i < n && word[i] != ch){
            i++;
        }

        if(word[i] == ch){
            int j = 0;
            while(j < i){
                swap(word[j++],word[i--]);
            }
        }

        return word;
    }
};

//OR Using Stack

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.length();
        int i = 0;
        stack<char> reverse;

        while(i < n && word[i] != ch){
            reverse.push(word[i++]);
        }

        if(word[i] == ch){
            word[0] = ch;
            i = 1;
            while(!reverse.empty()){
                word[i++] = reverse.top();
                reverse.pop();
            }
        }

        return word;
    }
};