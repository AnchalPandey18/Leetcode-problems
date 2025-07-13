class Solution {
public:
int f(int i,int j, string &s, string &p,vector<vector<int>>&dp){
 if(i <0 && j<0) return true;
 if(i < 0 && j>=0) return false;
 if(i>=0 && j<0){
    for(int q =0;q<=i;q++){
        if(p[q] !='*') return false;
    }
    return true;
 }
 if(dp[i][j] != -1) return dp[i][j];

 if(p[i] == s[j] || p[i] == '?'){
    return dp[i][j] = f(i-1,j-1,s,p,dp);
 }
 if(p[i] == '*'){
    return dp[i][j] = f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);
 }
 return dp[i][j] = false;
}
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};