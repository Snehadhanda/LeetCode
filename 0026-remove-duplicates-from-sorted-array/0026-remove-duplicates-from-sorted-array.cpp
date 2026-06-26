class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=1;
        int ans = 1;
        if(n==1) return n;
        while(j<n){
            if(nums[j]==nums[j-1]) {
                j++;
                continue;
            }
                nums[i+1] = nums[j];
                ans++;
                i++, j++;
        }
        return ans;
    }
};