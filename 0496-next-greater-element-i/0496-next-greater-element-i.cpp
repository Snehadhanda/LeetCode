class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int>st;
        unordered_map<int,int>nge;

        for(int i=n2-1; i>=0; i--){
            if(st.empty()){
                nge[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            if(st.top()>nums2[i]){
                nge[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            else if(st.top() <nums2[i]){
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                nge[nums2[i]] = -1;
                }
                else if(st.top()>nums2[i]){
                    nge[nums2[i]] = st.top();
                }
                st.push(nums2[i]);
            }
        }
        vector<int>ans;
        for(auto num:nums1){
            ans.push_back(nge[num]);
        }
        return ans;
    }
};