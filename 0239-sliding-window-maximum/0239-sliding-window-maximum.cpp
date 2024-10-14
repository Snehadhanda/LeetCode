class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int> dq;
        //first window ko process kro
        for(int i=0; i<k; i++){
            int element = nums[i];
            //jitne bhi queue ke andr chotey ele hai unko remove kro
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            //now insert kardo
            dq.push_back(i);
        }
        
        //remaining window ko process kro
                
        for(int i=k; i<nums.size(); i++){
            //ans store;
            ans.push_back(nums[dq.front()]);
            //removal
            //out of range jitne bhi elements hai unko remove kr denge
            if(!dq.empty() && i-dq.front() >=k){
                dq.pop_front();
            }
            //chotte ele ko pop krdo
            int ele = nums[i];
            while(!dq.empty() && ele> nums[dq.back()]){
                dq.pop_back();
            }
            //addition
            dq.push_back(i);
        }
        //last window ko process kro...kuki loop se last window ko process nhi kr pao ge
        ans.push_back(nums[dq.front()]);
        return ans;      
    }
};