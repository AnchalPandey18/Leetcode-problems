class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int mini = INT_MAX;
        int n= cost.size();
        for(int i=0;i<n;i++) {
            mini = min(mini,cost[i]);
            cost[i] = mini;
        }
        return cost;
    }
};