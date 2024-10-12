class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxCnt = 0;
        int currCnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                currCnt++;
            }
            else{
                maxCnt = max(maxCnt,currCnt);
                currCnt = 0;
            }            
        }
        maxCnt = max(maxCnt,currCnt);
        return maxCnt;
    }
};