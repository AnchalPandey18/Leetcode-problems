// class Solution {
//     private:
//     bool check(int start ,int v, vector<vector<int>>&graph, vector<int>&color) {
//         queue<int>q;
//         q.push(start);
//         color[start] =0;
//         while(!q.empty()) {
//             int node = q.front();
//             q.pop();
//             for(auto it:graph[node]) {
//                 if(color[it] == -1) {
//                     color[it] = !color[node];
//                     q.push(it);
//                 }
//                 else if(color[it] == color[node]) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     public:
//        bool isBipartite(vector<vector<int>>& graph) {
//         int v= graph.size();
//         vector<int>color(v,-1);
//         for(int i=0;i<v;i++) {
//             if(color[i] == -1) {
//                 if(check(i,v,graph,color) == false) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
bool dfs(int node, int col , vector<vector<int>> &graph, vector<int>&color) {
    color[node] = col;
    for(auto it:graph[node]) {
        if(color[it] == -1) {
            if(!dfs(it,1-col,graph,color)){
                return false;
            } 
        }
            else if(color[it] == col ) {
                return false;
            }
    }
    return true;
}
   bool isBipartite(vector<vector<int>>& graph) {
    int v = graph.size();
   vector<int>color(v,-1);
   for(int i=0;i<v;i++) {
    if(color[i] == -1) {
        if(!dfs(i,0,graph,color)) return false;
    }
   }
   return true;
  }
};