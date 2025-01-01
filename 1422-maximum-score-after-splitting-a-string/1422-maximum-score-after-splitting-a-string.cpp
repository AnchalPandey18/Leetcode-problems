class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int onescount =0;
        for(int i = 0 ; i<n; ++i) {
            if(s[i] == '1'){
                onescount++;
            }
        }
        int zeroescount = 0;
        int max_score = 0;
        for(int i=0; i<n-1;i++){
            if(s[i]=='1'){
             onescount--;
            }
            else {
             zeroescount++;
            }
             max_score = max(max_score,zeroescount+onescount);
        }
        return max_score;
    }
};