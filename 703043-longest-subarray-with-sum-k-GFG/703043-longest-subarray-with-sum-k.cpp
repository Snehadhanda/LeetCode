class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<long long,int> mp;
        long long sum = 0;
        int mlen = 0;
        
        for(int i=0; i<arr.size(); i++){
            sum+= arr[i];
            
            if(sum==k){
                mlen = max(mlen,i+1);
            }
            long long rem = sum-k;
            if(mp.find(rem) != mp.end()){
                int len = i-mp[rem];
                mlen = max(mlen,len);
            }
            //agar map me phle se sum nhi exit hoga tabhi 
            // add kre ge...vrna usko update nhi kre ge
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return mlen;
    }
};