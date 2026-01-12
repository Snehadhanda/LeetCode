class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        int Tcnt = 0;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            while(n != 0){
                cnt++;
                // n = nums[i];
                n = n/10;
            }
            if(cnt % 2 == 0) {
                Tcnt++;
            }
            cnt = 0;
        }
        return Tcnt;
    }
};