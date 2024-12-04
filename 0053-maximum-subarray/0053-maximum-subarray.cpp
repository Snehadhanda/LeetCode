class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++){
            //3 step honge
            //1. sum += current element
            sum+=nums[i];
            //2. update maxi
            maxi = max(maxi,sum);
            //3. if sum<0, then sum =0;
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};