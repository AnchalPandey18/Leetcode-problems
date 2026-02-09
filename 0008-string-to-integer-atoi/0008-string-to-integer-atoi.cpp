class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long result = 0;
        int sign = 1;
        int n= s.size();
        while(i<n && s[i] == ' ') i++;

        if(i == n) return 0;
 // manage sign
        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
   // read the digit

   while(i <n && isdigit(s[i])) {
    result = result*10 + (s[i] - '0');
    if(sign * result < INT_MIN) return INT_MIN;
    if(sign * result >INT_MAX) return INT_MAX;
    i++;
   }
   return (int)sign*result;
    }
};