/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//ITERATION
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode*curr = head;
//         while(curr != nullptr){
//             ListNode*nextNode = curr->next; //taki track lost na ho
//             curr->next = prev;
//             prev = curr;
//             curr = nextNode;
            
//         }
//         return prev;  //curr isiliye return nhi kra kuki curr end me null pe aayega
//     } 
// };

//RECURSION
class Solution {
public:
    ListNode* reverse(ListNode* &prev,ListNode* &curr){
        if(curr == nullptr){
            return prev;
        }
        //1 case hum solve kre ge baki recursion sambhale ga
        ListNode*nextNode = curr->next;
        curr->next = prev;
        //baki recursion sambhale ga
        ListNode* ans = reverse(curr,nextNode);
        return ans;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        return reverse(prev,curr);
    }
};