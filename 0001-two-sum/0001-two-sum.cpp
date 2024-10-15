class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size();i++){
            int num = nums[i];
            int moreNeeded = target-num;
            if(mp.find(moreNeeded) != mp.end()){
                return {mp[moreNeeded],i};
            }
            mp[num] = i;
        }
        //loop ke bahr mtlb koi bhi element nhi mille ga
        return {-1,-1};
    }
};