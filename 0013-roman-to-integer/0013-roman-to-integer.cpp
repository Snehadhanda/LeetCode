class Solution {
public:
    //logic is hume ye dekhne ke liye ki + hoga ya - uske liye next char dekhna hoga
    //agr ith char> i+1th char-> then ith char will be positive
    //agr ith char < i+1th char -> then ith char will be -ve
    int getVal(char ch){
        switch(ch){
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
        }
    }
    int romanToInt(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            char ch1 = s[i];
            if((i+1)<s.size() && getVal(ch1) < getVal(s[i+1])){
                sum -= getVal(ch1);
            }
            else{
                sum += getVal(ch1);
            }
        }
        return sum;
    }
};