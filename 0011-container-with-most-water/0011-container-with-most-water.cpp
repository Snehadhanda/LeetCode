class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        int area=-1;
        while(i<j){
            int hi = min(nums[i],nums[j]);
            int ar = hi*(j-i);
            area = max(ar,area);
            if(hi == nums[i]) i++;
            else j--; 
        }
        return area;
    }
};