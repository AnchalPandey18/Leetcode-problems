// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//     int j=0;
//     bool found = false;
//     for(int i=0; i<nums.size();i++){
//         if(nums[i]!=0){
//             nums[j]=nums[i];
//             j++;
//         }
//         else{
//          found= true;
//         }
//     }
//         if(found==false){
//             return;
//         }
//     for(int i=j;i<nums.size();i++){
//         nums[i]=0;
//       }
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int n= nums.size();
     int j=-1;
     for(int i=0;i<n;i++) {
        if(nums[i] == 0) {
            j =i;
            break;
        }
     }
     if(j == -1) return;

     for(int i=j+1;i<n;i++) {
        if(nums[i] != 0) {
            swap(nums[j],nums[i]);
            j++;
        }
     }
     return;
    }
};