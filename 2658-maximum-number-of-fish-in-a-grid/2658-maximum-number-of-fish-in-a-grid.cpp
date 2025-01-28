class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int Max =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    int c=0;
                    queue<pair<int,int>>t;
                    t.push({i,j});
                    while(!t.empty()){
                        auto [x,y] = t.front();
                        t.pop();
                        if(grid[x][y]>0){
                            c += grid[x][y];
                            grid[x][y] = 0;
                            if(x>0 && grid[x-1][y]>0) t.push({x-1,y});
                            if(x+1 <grid.size() && grid[x+1][y]>0) t.push({x+1,y});
                            if(y>0 && grid[x][y-1] >0) t.push({x,y-1});
                            if(y+1 <grid[0].size() && grid[x][y+1]>0) t.push({x,y+1});
                        }
                    }
                    Max = max(Max,c);
                }
            }
        }
        return Max;
    }
};