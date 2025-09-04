class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int ans =INT_MIN;
        int cnt = 0;
        int i=0;
        sort(nums.begin(), nums.end(),[](int a, int b){
            return a > b;
        });
        while(i<nums.size() && cnt<3){
            if(ans == nums[i]){
                i++;
                continue;
            }
            else {cnt++;
            ans = nums[i];
            }
            i++;
        }
        if(cnt==3) return ans;
        return nums[0];
    }
};