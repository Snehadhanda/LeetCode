class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        sort(nums.begin(), nums.end());
        int closesum = nums[0]+nums[1]+nums[2];
        int mindiff = abs(closesum - target);
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int currDiff = abs(sum-target);
                if(currDiff < mindiff){
                    mindiff = currDiff;
                    closesum = sum;
                }
                if (sum == target)
                    return sum;
                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return closesum;
    }
};