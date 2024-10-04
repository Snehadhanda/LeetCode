class Solution {
public:
    bool check(vector<int>& nums) {
        //we have to check if the array is rotated sorted or not....agr sorted and rotated hoga toh hmare pas sirf ek bar aaisa case aaye ga jhan pe arr[prev]>arr[curr]
        int n=nums.size();
        //hum ek count pointer le lenge or array me traverse krke dekhe ge ki kitni bar arr[prev]>arr[curr] true hogi....agr pura array traverse krne ke bad ek ya ek km bar hua toh mtlb array rotated and sorted hai...agr ek se zyada bar hua mtlb array rotated and sorted nhi hai
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>nums[(i+1)%n]){
                count++;
            }
        }
        if(count > 1) return false;
        return true;
    }
};