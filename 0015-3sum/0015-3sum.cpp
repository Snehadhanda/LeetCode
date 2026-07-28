class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> res;
        for (i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int sum = -1 * nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {

                int s = nums[l] + nums[r];
                if (s == sum) {
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++, r--;
                    while (l<r && nums[l] == nums[l - 1])
                        l++;
                    while (l<r && nums[r] == nums[r + 1])
                        r--;
                }

                else if (s > sum)
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
};