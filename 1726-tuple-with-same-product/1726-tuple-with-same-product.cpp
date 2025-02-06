class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>freq;
        int res =0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int prd = nums[i]*nums[j];
                freq[prd]++;
            }
        }
        for(auto& [prd,count]:freq){
            if(count>1){
                res += (count * (count - 1)) /2;
            }
        }
        return res *8;
    }
};