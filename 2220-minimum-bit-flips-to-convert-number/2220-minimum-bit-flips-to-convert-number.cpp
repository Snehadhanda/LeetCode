class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int count =0;
        int i=0;
        while(ans>0){
            int bit = ans % 2;
            if(bit & (1<<i) != 0){
                count++;
            }
            ans = ans/2;
            i++;
        }
        return count;
    }
};