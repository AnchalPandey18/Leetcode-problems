class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // for(int i=0;i<k;i++) {
        //      int last = nums[n-1];
        //     for(int j=n-1;j>0;j--) {
               
        //      nums[j] = nums[j-1];
        //     }
        //     nums[0] = last;
        // }
        if(n==0)return;
        k %= n;
        if(k==0) return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};