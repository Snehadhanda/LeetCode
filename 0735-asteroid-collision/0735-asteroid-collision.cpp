class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
       
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) st.push(nums[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top() < -nums[i]){
                    st.pop();
                }
                if(!st.empty() && (st.top() == -nums[i])) st.pop();
                else if(st.empty() || st.top()<0){
                    st.push(nums[i]);
                }
            }
        }
        vector<int> ans(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};