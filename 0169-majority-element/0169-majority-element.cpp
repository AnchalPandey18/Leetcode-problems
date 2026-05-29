class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el =0;
        int cnt =0;
        for(int num:nums) {
            if(cnt == 0) {
                el = num;
                cnt++;
            }
            else if(el == num){
                cnt++;
            }
            else {
                cnt--;
            }

        }
        return el;
    }
};