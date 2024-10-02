class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //step1: make a copy of arr
        vector<int> a_copy = arr;
        //2- sort the copied arr
        sort(a_copy.begin(), a_copy.end());
        int rank = 1;
        //store the elements of array in map
        unordered_map<int,int> mp;
        for(int i=0; i<a_copy.size();i++){
            if(mp.find(a_copy[i])==mp.end()){ //agar value map me alrdy present hogi toh hum kuch nhi kre ge.....lkin agar value mapme nhi hai...mtlb a[i] ko dekhtey dekhtey end tk punch gaye map ke or value nhi milli(mtlb nayi value ahi toh hum us value ko map me store kr denge with its rank)
                mp[a_copy[i]] = rank;
                rank++;
            }
        }
        //then make an ans array to store rank
        vector<int>ans(arr.size());
        //traverse thorugh the ans array and store the rank of each element in the same order fo the input array
        for(int i=0; i<ans.size(); i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};