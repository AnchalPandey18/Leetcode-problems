class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(v);
        vector<int>indegree(v,0);
        for(auto it:prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
       queue<int>q;
       for(int i=0;i<v;i++) {
        if(indegree[i] == 0) {
            q.push(i);
         }
       }

        int count =0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(auto nei:adj[node]) {
             indegree[nei]--;
             if(indegree[nei] ==0) q.push(nei);
            }
        }
        return count == v;
    }
};