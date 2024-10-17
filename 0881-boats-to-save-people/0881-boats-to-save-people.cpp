class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat = 0;
        sort(people.begin(), people.end());
        int s=0;
        int e=people.size()-1;
        while(s<=e){
            if((people[s]+people[e])<=limit){
                s++;
                e--;
                boat++;
            }
            else{
                boat++;
                e--;
            }
        }
        return boat;
    }
};