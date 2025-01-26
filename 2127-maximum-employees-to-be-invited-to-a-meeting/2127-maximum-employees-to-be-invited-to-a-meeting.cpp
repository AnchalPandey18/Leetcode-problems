class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n= favorite.size();
        vector<int>inDegree(n,0),depth(n,1);
        

        for(int fav:favorite){
            inDegree[fav]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int nxt = favorite[node];
          depth[nxt] = max(depth[nxt],depth[node]+1);
          if(--inDegree[nxt] ==0) q.push(nxt);
            

            
        }
        int maxCycle={0},totalChain={0};
        for(int i=0;i<n;i++){
            if(inDegree[i] == 0) continue;
                int current=i,cycleLen{0};
                while(inDegree[current]!=0){
                    inDegree[current]=0;
                    cycleLen++;
                    current = favorite[current];
                }

                
                if(cycleLen == 2){
                    totalChain += depth[i]+depth[favorite[i]];
                } else{
                    maxCycle = max(maxCycle,cycleLen);
                }
            
        }
        return max(maxCycle,totalChain);
    }
};
static auto init =[]() {ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();