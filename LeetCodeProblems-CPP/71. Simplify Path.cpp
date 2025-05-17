// Idea: Push all directories in a stack and when enconter ".." pop the directory

#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string c;
        int i = 0, n = path.size();
        while (i < n) {
            c.clear();
            while(path[i]!='/' && i<n)
            {
                c += path[i];
                i++;
            }
            if(c==".." && !s.empty())
            {
                s.pop();
            }
            else if(c!=".." && c!="." && !c.empty())
            {
                s.push(c);
            }
            i++;
        }
        c.clear();
        if(s.empty())
        {
            c="/";
        }
        while (!s.empty()) {
            c = "/" + s.top() + c;
            s.pop();
        }
        return c;
    }
};

int main() {
    string spath, path;
    cout<<endl<<"Enter Path: ";
    getline(cin, path);
    Solution s;
    spath = s.simplifyPath(path);
    cout << endl << spath << endl << endl;
    return 0;
}
