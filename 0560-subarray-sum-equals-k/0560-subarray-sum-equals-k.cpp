class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n = nums.size();
        // int cnt= 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum = 0;
        //         for(int m =i;m<=j;m++){
        //             sum += nums[m];
        //         }
        //         if(sum == k) {
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;


                int n = nums.size();
        int cnt= 0;
        for(int i=0;i<n;i++){
             int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};