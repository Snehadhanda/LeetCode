class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = nums[0];
        int i = 0, j=1,k=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                swap(nums[k],nums[j]);
                i++,k++,j++;
            }
        }
        return k;
    }
};