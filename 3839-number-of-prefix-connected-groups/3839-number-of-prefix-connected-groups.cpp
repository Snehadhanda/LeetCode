class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for(auto &d: words){
            if(d.size() < k) continue;
            string p = d.substr(0,k);
            mp[p]++;
        }
        int cnt = 0;
        for(auto &x:mp) if(x.second >= 2) cnt++;

        return cnt;
    }
};