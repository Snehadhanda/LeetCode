/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//sbse bekr approch jis se interviewer hmesha mna kre ga
//using map
//isme hum address ke acc check kre ge kuki vo unique hoga....hum yhan pe value ke acc nhi kre ge kuki value repeat bhi ho skti hai jb loop na bhi bn rha hai.....toh b=value ke case me loop hona jruri nhi hai
//isilye agr traversal ke time pe jb koi address repeat ho jaye...mtlb loop is present
//approch is ki hum ek map create kr lenge....jiske andr address or status hoga.....traverse krtey jaye ge or jo jo address visit ho jaye ga usko true mark kr denge....jb koi address alrdy visited hoga toh mtlb there is a loop
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool>table;
        ListNode*temp = head;
        while(temp !=nullptr){
            //hum yhan pe nrml LL man ke chl rhe hai
            if(table[temp]==false){
                //agr table me temp present nhi hai....mtlb not visited hai toh usko visited mark kr denge
                table[temp]=true;
            }
            else{
                //agr table ke andr temp alrdy visited hai.....mtlb dubara visit kr rhe hai....i.e cycle is present
                return true;
            }
            temp = temp->next;
        }
        //loop se bahr tabhi aayega jb temp null ho jayega.....mtlb loop present nhi hai toh return false
        return false;
    }
};