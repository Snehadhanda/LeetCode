class Solution {
public:
    vector<int>nextSmallerEle(vector<int> arr){
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);
        for(int i=arr.size()-1; i>=0; i--){
            int curr = arr[i];
            while(st.top() != -1 && st.top() > curr){ //hum equal ke case me pop nhi kre ge
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
        return ans;
    }
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>finalPrice(prices.size());
        vector<int>discount = nextSmallerEle(prices);
        for(int i=0; i<prices.size(); i++){
             if(discount[i] == -1){
                finalPrice[i] = prices[i]; //ab agar smaller exist nhi kre ga toh discount 0 hoga mtlb jo price hai vhi final price hoga
            }
            else{
                finalPrice[i] = prices[i]-discount[i];
            }
        }
        return finalPrice;
    }
};