class Solution {
public:
 bool isPrefixAndSuffix(const string &s1,const string &s2){
    int n= s1.size();
    int m = s2.size();
    if(n>m) return false;
    return s2.substr(0,n) == s1 && s2.substr(m-n,n) == s1;
 }
int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count =0;
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             if(isPrefixAndSuffix(words[i],words[j])){
                count++;
             }
            }
        }
        return count;
    }
};