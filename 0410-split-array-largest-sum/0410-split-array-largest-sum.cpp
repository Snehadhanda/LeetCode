class Solution {
public:
    bool isPos(vector<int>& nums, int cap, int k){
        int sum=0,cnt=1;
        for(int i=0; i<nums.size(); i++){
            if((sum+nums[i])>cap){
                cnt++;
                sum = nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        if(cnt <= k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN, sum=0;
        for(int i=0; i<nums.size(); i++){
            maxi = max(nums[i],maxi);
            sum += nums[i];
        }
        int lo = maxi, hi = sum;
        int mid, ans=-1;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(isPos(nums,mid,k)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};