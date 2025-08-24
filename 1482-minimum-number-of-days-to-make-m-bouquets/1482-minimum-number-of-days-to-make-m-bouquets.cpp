class Solution {
public:
bool isPossible(vector<int>& bloomDay, int day,int k,int m){
    int cnt =0, nb=0;
    for(int i=0; i<bloomDay.size(); i++){
        if(bloomDay[i]<=day) cnt++;
        else{
            nb+= (int)(cnt/k);
            cnt = 0;
        }
    }
    nb += (int)(cnt/k);
    if(nb >= m) return true;
    else return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k > n) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int lo = mini, hi = maxi;
        int mid, ans= -1;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(isPossible(bloomDay,mid,k,m)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};