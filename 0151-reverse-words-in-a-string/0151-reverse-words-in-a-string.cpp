// class Solution {
// public:
//     string reverseWords(string s) {
//         s+=" "; //space is added so that last word of the string is also processed 
//         stack<string>st;
//         string str = "";
//         for(int i=0; i<s.length(); i++){
//             if(s[i]==' '){
//                 st.push(str);
//                 str = "";
//             }
//             else str+=s[i];
//         }
//         string ans = "";
//         while(st.size() != 1){
//             ans +=st.top()+" ";
//             st.pop();
//         }
//         ans+=st.top();
//         return ans;
//     }
// };
class Solution {
public:
    string reverseWords(string s){
        int left =0;
        int right = s.length()-1;
        string temp="";
        string ans = "";
        while(left<=right){
            char ch = s[left];
            if(ch != ' '){
                temp +=ch;
            }
            else if(ch == ' '){
                if(temp != ""){
                if(ans != ""){
                    ans = temp +' '+ans;
                }
                else{
                    ans = temp;
                }
                temp="";
            }
            }
            left++;
        }
        if(temp !=""){
            if(ans!="") ans= temp+' '+ans;
            else ans = temp;
        }
        return ans;
    }
};