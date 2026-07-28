class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=0) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        if(b.size()==0){
            for(int i=0; i<nums.size(); i++){
                nums[i] = nums[i]*nums[i];
            }
            return nums;
        }
        if(a.size()==0){
            for(int i=0; i<nums.size(); i++){
                nums[i]= nums[i]*nums[i];
            }
            reverse(nums.begin(),nums.end());
            return nums;
        }

        for(int i=0; i<a.size(); i++){
            a[i] = a[i]*a[i];
        }
        for(int i=0; i<b.size(); i++){
            b[i] = b[i]*b[i];
            
        }
        reverse(b.begin(), b.end());
        


        //merge
        int i=0, j=0;
        vector<int> res;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                res.push_back(a[i]);
                i++;
            }
            else{
                res.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            res.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            res.push_back(b[j]);
            j++;
        }
        return res;
    }
};