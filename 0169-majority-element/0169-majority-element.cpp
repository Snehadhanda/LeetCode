class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            mp[num]++;
        }
        for(auto it:mp){
            if(it.second > n/2){
                return it.first;
            }
        }
        return -1;
    }
};