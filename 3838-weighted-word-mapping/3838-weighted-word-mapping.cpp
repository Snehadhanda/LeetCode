class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(auto &s:words){
            int sum = 0;

            for(char c:s){
                sum += weights[c-'a'];
            }

            int r = sum%26;
            char ch = 'z'-r; //to reverse map it 
            ans.push_back(ch);

        }
        return ans;
    }
};