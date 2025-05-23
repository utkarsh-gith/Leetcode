class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> str;

        int n = 0;
        string res = "";

        for(char& c : s){

            if(isdigit(c)){

                n = n * 10 + (c - '0');

            }else if(c == '['){

                str.push(res);
                res = "";

                num.push(n);
                n = 0;

            }else if(c == ']'){

                int i = num.top();
                num.pop();

                string temp1 = "";
                while(i > 0){
                    temp1 += res;
                    i--;
                }

                string temp2 = str.top();
                str.pop();

                res = temp2 + temp1;
            }else{
                res += c;
            }
        }

        return res;
    }
};

// OR NEAT

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string result = "";
        int i = 0;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                counts.push(num);
            } else if (s[i] == '[') {
                resultStack.push(result);
                result = "";
                i++;
            } else if (s[i] == ']') {
                string temp = resultStack.top();
                resultStack.pop();

                int repeatTimes = counts.top();
                counts.pop();

                string repeated = "";
                for (int j = 0; j < repeatTimes; j++) {
                    repeated += result;
                }

                result = temp + repeated;
                i++;
            } else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};