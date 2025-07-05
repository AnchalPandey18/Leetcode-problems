class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<int>prev(amount+1,0),cur(amount+1,0);
      for(int t=0;t<=amount;t++) prev[t] = (t%coins[0] == 0);
      for(int i=1;i<n;i++){
        for(int t=0;t<=amount;t++){
            long nottake = prev[t];
            long take =0;
            if(coins[i] <= t) take = cur[t-coins[i]];
            cur[t]= nottake+take;
        }
        prev = cur;
      }
      return prev[amount];
        
    }
};