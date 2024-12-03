class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1; i>=0; i--){
            //agar digit[i] i.e ones digit jo hai vo <9 hui toh simply add 1 to it
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        //agr sari digit 9 hongi toh leading 1 aa jayega;
        digits.insert(digits.begin(),1);
        return digits;
    }
};