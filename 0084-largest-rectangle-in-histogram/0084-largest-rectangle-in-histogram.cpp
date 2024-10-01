//right/left direction me koi bhi bar tabhi extend ho paye gi jb uski adjacent bar equal ya larger ho......small wale case me extend nhi ho skti
//area = width(upto where the bar can extend) * height of the bar
//so we will calculate the area for each bar and then out of all the areas we will find the max area
//kissi bhi bar ko hum vertically extend nhi kr sktey....sirf horizontal extension wala case possible hai
//concept toh samjh lia now main target is width find out krna....kuki height toh hme alredy pata hai
//width = next-prev-1
//next - index of next smaller element(alrdy done in vs)
//prev - index of prev smaller element("")
//Point to remember: jab bhi hum next and prev smaller access kr rhe hotey hai...toh prev me agr hume nhi milta smaller toh hum vhan assume kr sktey haiki 0 height ki bar hai or size -1 hai.....lkin jb next pe jatey hai toh hmara index -1 toh ho hi nhi skta.....isiliye agr next me kuch nhi hai toh assume kr lenge 0 height ki bar hai or size uske index ke jitna hai....[2,4] me yhi gadbad ho rhi thi ki hum next me bhi smaller -1 ko le rhe the
//Dusri chij jo dhyan me rakhni hai vo hai ki hum jb bhi prev and next smaller nikale ge toh hum ye dekhtey hai ki stack empty toh nhi kuki lkin vhan pe hum ye dekhe ge ki stack ka top -1 toh nhi kuki humne stack ke andr index store kre hai...or us case me possibility hai ki st.top() me -1 ho...toh hum arr[-1] access kr rhe honge and as we know -1 index ko toh hum access kr hi nhi sktey...isiliye empty na check krke ye chk kre ge ki st.top -1 toh nhi
class Solution {
public:
    vector<int>nextSmallerEle (vector<int>arr) 
    {
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);
        for(int i= arr.size()-1; i>=0; i--){
            int curr = arr[i];
            //ans find kre ge curr ke liye
            while(st.top() != -1 && arr[st.top()] >= curr) {
                st.pop(); //greater element hoga toh pop krtey rhe ge
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PrevSmallerEle(vector<int>arr)
{
    
    vector<int>ans(arr.size());  
    stack<int>st;
    st.push(-1); 
    for(int i=0; i<arr.size(); i++){
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }
        ans[i] = st.top(); 
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallerEle(heights);
        for(int i=0; i<heights.size();i++){
            if(next[i] == -1){
                next[i] = heights.size();
            }
        }
        vector<int>prev = PrevSmallerEle(heights);
        vector<int>area(next.size());
        for(int i=0; i<next.size(); i++){
            int width = next[i]-prev[i] - 1;
            int length = heights[i];
            int currArea = width * length;
            area[i] = currArea;
        }
        int maxi= INT_MIN;
        for(int i=0; i<area.size();i++){
            maxi = max(maxi, area[i]);
        }
        return maxi;
    }
};