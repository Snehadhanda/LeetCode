class Solution {
public:
    typedef pair<char,int> P;
    
    string frequencySort(string s) {
        //a-z and A-Z hai and we know A=65 and z=122 toh
        vector<P> vec(123);
        for(char &ch : s){
            int freq = vec[ch].second;
            vec[ch] = {ch, freq+1};
        }
        auto lambda = [&](P &p1, P &p2){
        return p1.second>p2.second;
    };
        sort(vec.begin(),vec.end(), lambda);
        
        string result = "";
        for(int i=0; i<vec.size();i++){
            char ch = vec[i].first;
            int freq = vec[i].second;
            string temp = string(freq,ch);
            
            result += temp;
        }
        return result;
    }
};