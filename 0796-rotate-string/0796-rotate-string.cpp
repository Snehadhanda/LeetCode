class Solution {
public:
    bool rotateString(string s, string goal) {
        //if we concatenate the string s with itself then it will have all possible rotations
        int n = s.length();
        int m = goal.length();
        if(m != n){
            return false;
        }
        string str = s+s;
        if(str.find(goal)!=string::npos){
            return true;
        }
        else return false;
    }
};