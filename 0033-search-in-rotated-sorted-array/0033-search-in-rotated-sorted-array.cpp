class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s <= e){
            int mid = s+(e-s)/2;
            
            if(target == nums[mid]){
                return mid;
            }
            if(nums[s] <= nums[mid]){  //agar left part sorted hai
                if(nums[s]<=target && target <=nums[mid]){
                //mtlb 1st wale part me target milne ke chance hai toh 2nd half ko eleminate kr denge
                e = mid-1;
                }
            else{
                s = mid + 1;
                }
            }
            else{  //of right part is sorted
                if(nums[mid]<=target && target <= nums[e]){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return -1; //agar pura array traverse krne ke bad bhi nhi milta toh mtlb vo element present hi nhi hai
    }
};