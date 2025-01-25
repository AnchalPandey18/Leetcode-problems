class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>numSor(nums);
        sort(numSor.begin(),numSor.end());
        int currGroup =0;
        unordered_map<int,int>numGroup;
        numGroup.insert(pair<int,int>(numSor[0],currGroup));

        unordered_map<int,list<int>> grpList;
        grpList.insert(pair<int,list<int>>(currGroup,list<int>(1,numSor[0])));

        for(int i=1;i<nums.size();i++){
            if(abs(numSor[i]-numSor[i-1]) >limit){
                currGroup++;
            }
            numGroup.insert(pair<int,int>(numSor[i],currGroup));
            if(grpList.find(currGroup)==grpList.end()){
                grpList[currGroup] = list<int>(); 
                           }
              
        grpList[currGroup].push_back(numSor[i]);
        }
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int group = numGroup[num];
            nums[i]= *grpList[group].begin();
        grpList[group].pop_front();
        }
        return nums;
    }


};