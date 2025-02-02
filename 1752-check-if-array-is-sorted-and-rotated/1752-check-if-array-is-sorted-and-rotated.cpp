class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
        bool isIncrease = true;
        int pivote = 0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                pivote = i;
                isIncrease = false;
                break;
            }
        }
        if(isIncrease){
            return true;
        }
        int x = n-pivote;
        vector<int> rotated(n);
        for(int i=0;i<n;i++){
            rotated[(i+x)%n] = nums[i];
        }
        for(int i=1;i<n;i++){
            if(rotated[i]<rotated[i-1]){
                return false;
            }
        }
        return true;
    }
};