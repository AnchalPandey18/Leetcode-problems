class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        if(n == 0 || n == 1) return cost[n];
         int prev2 = cost[0];
         int prev1 = cost[1];
         for(int i=2;i<n;i++){
            int cur = cost[i] + min(prev2,prev1);
            prev2 = prev1;
            prev1 = cur;
         }
         return min(prev1,prev2);
    }
};