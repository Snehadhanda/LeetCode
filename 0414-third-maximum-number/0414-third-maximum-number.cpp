class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        vector<int>v(st.begin(),st.end());
        sort(v.begin(), v.end(),[](int a, int b){
            return a>b;
        });
        if(v.size() < 3) return v[0];
        else return v[2];
    }
};