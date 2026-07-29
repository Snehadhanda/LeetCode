class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res;
        int min_dif = INT_MAX;

        for(int i=0; i<nums.size()-2; i++){
            int l=i+1;
            int r=nums.size()-1;

            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];

                if(sum == target){
                    return sum;
                }
                else if(sum < target){
                    int diff = abs(sum-target);
                    if(diff < min_dif){
                        min_dif = diff;
                        res = sum;
                    }
                    l++;
                }
                else{
                    int diff = abs(sum-target);
                    if(diff < min_dif){
                        min_dif = diff;
                        res = sum;
                    }
                    r--;
                }
            }
        }
        return res;
    }
};