class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        unordered_set<char>st;
        int mLen = 0;

        for(int r =0; r<n; r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            mLen = max(mLen, r-l+1);
        }
        return mLen;
    }
};