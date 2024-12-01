class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        long ans =0;
        int sign = 1;
        while(i<s.length() && s[i]==' '){
            i++;
            
        }
        s=s.substr(i);
        // if(i==s.length()) return 0;
        if(s[0]=='-'){
            sign = -1;
        }
        if(s[0]=='+') sign = 1;
        int Max = INT_MAX;
        int Min = INT_MIN;
        i= (s[0]== '+'|| s[0]=='-')? 1:0;
        
       while(i<s.length() && isdigit(s[i])){
           int digit = s[i]-'0';
           if(ans> (Max-digit)/10){
               return (sign==1)? Max:Min;
           }
            ans = ans*10 +digit;
            i++;
        }
        
        return (int)ans*sign;
    }
};