class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count =0;
        int m = pref.size();
        for(string &word:words){
          //  if(word.find(pref) == 0){
            if(word.substr(0,m) == pref){ 
                count++;
            }
        }
        return count;
    }
};