class Solution {
public:
    int Expand(string s,int i, int j){
        int count =0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            if(s[i]==s[j]){
                count++;
                i--;
                j++;
            }
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int centre =0; centre<s.length(); centre++){
            int oddcount = Expand(s, centre, centre);
            int evencount = Expand(s, centre, centre+1);
            totalCount = totalCount + oddcount + evencount;
        }
        return totalCount;
    }
};