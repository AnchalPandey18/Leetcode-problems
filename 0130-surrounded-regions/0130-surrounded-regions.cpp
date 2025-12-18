                     // DFS Traversal

// class Solution {
//     private:
//     void dfs(int row,int col,vector<vector<int>>&vis, vector<vector<char>>&board,int delrow[], int delcol[]) {
//         int n= board.size();
//         int m= board[0].size();
//         vis[row][col] = 1;
//         for(int i=0;i<4;i++){
//             int nrow = row + delrow[i];
//             int ncol = col+delcol[i];
//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
//             dfs(nrow,ncol,vis,board,delrow,delcol);
//         }
//         }
//     }
// public:
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m= board[0].size();
//         int delrow[]= {-1,0,1,0};
//         int delcol[] = {0,1,0,-1};
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         // first row and last row 
//         for(int j=0;j<m;j++) {
//             // first row
//             if(!vis[0][j] && board[0][j] =='O') {
//                 dfs(0,j,vis,board,delrow,delcol);
//             }
//             //last row
//             if(!vis[n-1][j] && board[n-1][j] == 'O') {
//                 dfs(n-1,j,vis,board,delrow,delcol);
//             }
//         }
//         for(int i=0;i<n;i++){
//             //first col
//             if(!vis[i][0] && board[i][0] == 'O') {
//                 dfs(i,0,vis,board,delrow,delcol);
//             }
//             //last col

//             if(!vis[i][m-1] && board[i][m-1] == 'O') {
//                 dfs(i,m-1,vis,board,delrow,delcol);
//             }
//         }
         
//          for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++) {
//                 if(!vis[i][j] && board[i][j] == 'O') {
//                     board[i][j] ='X';
//                 }
//             }
//          }
//     }
// };

                         // BFS Traversal

class Solution{
  public:

  void solve(vector<vector<char>>&board) {
     int n = board.size();
     int m = board[0].size();
     vector<vector<int>>vis(n,vector<int>(m,0));
     queue<pair<int,int>>q;
      // boundary conditions
      for(int i=0;i<n;i++) {
        if(board[i][0] == 'O'){
            vis[i][0] =1;
            q.push({i,0});
        }
        if(board[i][m-1] == 'O') {
            vis[i][m-1] =1;
            q.push({i,m-1});
        }
      }

      for(int j=0;j<m;j++) {
        if(board[0][j] == 'O') {
            vis[0][j] =1;
            q.push({0,j});
        }
        if(board[n-1][j] == 'O') {
            vis[n-1][j] =1;
            q.push({n-1,j});
        }
      }

     int delrow[] = {-1,0,1,0};
     int delcol[] ={0,1,0,-1};
      while(!q.empty()) {
         int row = q.front().first;
         int col= q.front().second;
          q.pop();

          for(int i=0;i<4;i++) {
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 'O' && !vis[nrow]  [ncol]) {
            vis[nrow][ncol] =1;
            q.push({nrow,ncol});
         }
        }
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(board[i][j] == 'O' && !vis[i][j]) {
                board[i][j] ='X';
         }
       }
     } 
  }
};