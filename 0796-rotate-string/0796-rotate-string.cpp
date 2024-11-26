class Solution {
public:
    bool rotateString(string s, string goal) {
        // //if we concatenate the string s with itself then it will have all possible rotations
        // int n = s.length();
        // int m = goal.length();
        // if(m != n){
        //     return false;
        // }
        // string str = s+s;
        // if(str.find(goal)!=string::npos){
        //     return true;
        // }
        // else return false;
        
        
        //METHOD 2:
        int n=s.length();
        int m = goal.length();
        for(int i=0; i<n; i++){
            rotate(s.begin(), s.begin()+1, s.end());
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};