class Solution {
public:
    string reverseWords(string s) {
        //add a space at end so that last word can be processed
        s+=' ';
        stack<string>st;
        string str = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] ==' '){
                if(!str.empty()){
                    st.push(str);
                    str = "";
                }
                
            }
            else{
                str+=s[i];
            }
        }
        string ans ="";
        while(st.size()>1){
            ans+=st.top() + " ";
            st.pop();
        }
        ans+=st.top();
        return ans;
    }
};