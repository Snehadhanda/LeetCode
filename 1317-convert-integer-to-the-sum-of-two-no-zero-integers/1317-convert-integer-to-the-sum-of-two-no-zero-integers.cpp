class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=0; i<n;i++){
            int l = i;
            int r= n-i;
            if(!containZero(l) && !containZero(r)){
                return{l,r};
            }
        }
        return {};
    }
    bool containZero(int n){
        string str = to_string(n);
        return str.find('0') != string::npos;
    }
};