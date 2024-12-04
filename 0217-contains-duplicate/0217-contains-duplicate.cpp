class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int num = nums[i];
            mp[num]++;
        }
        for(auto i:mp){
            if(i.second >= 2){
                return true;
            }
        }
        return false;
    }
};