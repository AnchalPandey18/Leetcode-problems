class Solution {
public:
    int lcs(string ss, string t)
{
	//Write your code here
	int n= ss.size();
	int m= t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	//return f(n-1,m-1,s,t,dp);
	for(int j=0;j<=m;j++) dp[0][j] =0;
	for(int i=0;i<=n;i++) dp[i][0] =0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
       if(ss[i-1] == t[j-1]) {
		    dp[i][j] = 1+dp[i-1][j-1];
	   }
	   else {
		    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	   }
		}
	}
	return dp[n][m];
}

int longestPalindromeSubsequence(string str)
{
    // Write your code here.
    string t =str;
    reverse(t.begin(),t.end());
    return lcs(str,t);
}
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubsequence(s);
    }
};