class Solution {
public:
   string ans = "";
   int cnt =0;

   void dfs(string &cur ,int n ,int k ) {
    if(cur.size() == n) {
        cnt++;
        if(cnt == k) ans = cur;
        return;
    }
      for(char ch ='a';ch<= 'c';ch++) {
        if(!cur.empty() && cur.back()==ch) continue;
        cur.push_back(ch);
        dfs(cur,n,k);
        cur.pop_back();
      }
   }
    string getHappyString(int n, int k) {
        string cur ="";
        if(k > 3* pow(2,n-1)) return "";
        dfs(cur,n,k);
        return ans;
    }
};