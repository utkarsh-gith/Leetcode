class Solution {
public:
    bool checkEqual(int a[26], int b[26]){

        for(int i=0;i<26;i++){
            if(a[i] != b[i]){
                return 0;
            }
        }

        return 1;

    }
    bool checkInclusion(string s1, string s2) {

        int count1[26] = {0};
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1>n2){
            return 0;
        }

        for(int i=0;i<n1;i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int i = 0;
        int count2[26] = {0};

        while(i<n1){
            int index = s2[i++] - 'a';
            count2[index]++;
        }

        if(checkEqual(count1,count2)){
            return 1;
        }

        while(i<n2){
            int index = s2[i] - 'a';
            count2[index]++;

            index = s2[i - n1] - 'a';
            count2[index]--;

            if(checkEqual(count1,count2)){
                return 1;
            }

            i++;
        }

        return 0;
    }
};

// OR very high time comlexity

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        array<int,26> count = {0};
        int n1 = s1.length();
        int n2 = s2.length();

        for(int i=0;i<n1;i++){
            int index = s1[i] - 'a';
            count[index]++;
        }

        for(int i=0;i<n2-n1+1;i++){

            array<int,26> c = count;

            for(int j=0;j<n1;j++){
                int index = s2[j+i] - 'a';
                c[index]--;
            }

            bool ans = true;

            for(int j=0;j<26;j++){
                if(c[j] != 0){
                    ans = false;
                    break;
                }
            }

            if(ans){
                return 1;
            }
        }

        return 0;
    }
};