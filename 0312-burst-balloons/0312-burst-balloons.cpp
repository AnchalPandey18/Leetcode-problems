class Solution {
public:
    int f(int i,int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int ind =i;ind<=j;ind++){
            int coins = nums[i-1]*nums[ind]*nums[j+1] + f(i,ind-1,nums,dp) + f(ind +1 ,j,nums,dp);
            maxi = max(maxi,coins);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
    }
};