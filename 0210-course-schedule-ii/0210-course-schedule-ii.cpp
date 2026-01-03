class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
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
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto nei:adj[node]) {
                indegree[nei]--;
                if(indegree[nei] ==0) q.push(nei);
            }
        }
        if(topo.size() == v) return topo;
        return{};
      
    }
};