class Solution {
public:
bool isPalindrom(int i,int j, string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
// int f(int i,int n, string &s, vector<int>&dp){

//     int mini =INT_MAX;
//     if(i == n){
//         return 0;
//     }
//     if(dp[i] != -1) return dp[i];
//     for(int j =i;j<n;j++){
//         if(isPalindrom(i,j,s)) {
//             int cuts = 1+f(j+1,n,s,dp);
//             mini = min(mini,cuts);
//         }
//     }
//     return dp[i] = mini;
// }
    int minCut(string s) {
       int n = s.size();
       vector<int>dp(n+1,0);
          dp[n] =0;
        
       for(int i =n-1;i>=0;i--){
       int mini =INT_MAX;
        for(int j =i;j<n;j++){
            if(isPalindrom(i,j,s)){
                int cuts = 1+dp[j+1];
                mini = min(mini,cuts);
            }
        }
        dp[i] = mini;
       }
       return dp[0]-1;
    }
};