class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>result(n);

        vector<bool>isPresentA(n+1,false);

        vector<bool>isPresentB(n+1,false);

        for(int i=0;i<n;i++){
            isPresentA[A[i]] = true;
            isPresentB[B[i]] = true;

            int count =0;

            for(int num = 1; num<=n;num++){
                if(isPresentA[num] == true && isPresentB[num] == true){
                    count++;
                }
            }
            result[i]= count;
        }
        return result;
    }
};