class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int newIdx = (i+k)%n;
            ans[newIdx] = nums[i];
        }
        nums = ans;
    }
};