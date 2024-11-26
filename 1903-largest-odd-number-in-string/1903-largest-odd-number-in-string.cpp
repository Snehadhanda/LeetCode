class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size(); i>=0; i--){
            //it is used to convert string to integer
            if((num[i]-'0') % 2 !=0){
                //if given int is odd ten return the substring from start to i(induclusive)
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};