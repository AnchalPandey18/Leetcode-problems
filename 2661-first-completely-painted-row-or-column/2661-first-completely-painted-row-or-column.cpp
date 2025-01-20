class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>rowId(n) , colId(m);
        unordered_map<int,pair<int,int>>pos;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = mat[i][j];
                pos[val] = {i,j};
            }
        }
        for(int k= 0; k < arr.size();k++){
            int num = arr[k];
            auto[i,j] = pos[num];

            rowId[i]++;
            colId[j]++;

            if(rowId[i] == m || colId[j] == n){
                return k;
            }
        }
        return -1;
    }
};