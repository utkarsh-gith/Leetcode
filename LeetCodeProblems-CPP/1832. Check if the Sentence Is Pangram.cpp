class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> check(26,false);

        for (char& s : sentence) {
            check[s - 'a'] = true;
        }

        for (bool c : check) {
            if (c == false) {
                return false;
            }
        }

        return true;
    }
};