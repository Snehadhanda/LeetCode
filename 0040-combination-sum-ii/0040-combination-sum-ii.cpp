class Solution {
public:
    void Combination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp){
            if(target == 0){
                ans.push_back(temp);
                return;
        }
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]== arr[i-1]) continue;
            if(arr[idx]>target) break;
            temp.push_back(arr[i]);
            Combination(i+1,target-arr[i], arr, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        Combination(0,target,candidates,ans,temp);
        return ans;
    }
};