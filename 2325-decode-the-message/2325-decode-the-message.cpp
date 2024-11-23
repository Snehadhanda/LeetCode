class Solution {
public:
    string decodeMessage(string key, string message) {
        char mp[280] ={0};
        char start = 'a';
        for(auto ch: key){
            if(ch != ' ' && mp[ch] == 0){
                mp[ch] = start;
                start++;
            }
        }
        string ans;
        for(auto ch:message){
            if(ch == ' '){
                ans.push_back(' ');
            }
            else{
                char dechar = mp[ch];
                ans.push_back(dechar);
            }
        }
        return ans;
    }
};