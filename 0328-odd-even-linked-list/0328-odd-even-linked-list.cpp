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

//THIS SOL WILL TAKE TC-O(N) AND SC- O(N)
// class Solution {
// public:
//     void OddEven(ListNode* &head, vector<int> &arr){
//         ListNode*temp = head;
//         while(temp != nullptr){
//             arr.push_back(temp->val);
//             temp = temp->next;
//             if(temp != nullptr){
//                 temp = temp->next;
//             }
//         }
//         if(temp) arr.push_back(temp->val);
//         if(head->next != nullptr){
//             temp = head->next;
//             while(temp!=nullptr){
//             arr.push_back(temp->val);
//             temp = temp->next;
//             if(temp != nullptr){
//                 temp = temp->next;
//                 }
//             }
//             if(temp) arr.push_back(temp->val);
//         }
//     }
//     ListNode* oddEvenList(ListNode* head) {
//         ListNode* temp = head;
//         vector<int>arr;
//         if(head == nullptr){
//             return nullptr;
//         }
//         if(head->next == nullptr){
//             return head;
//         }
//         OddEven(head,arr);
//         int i=0;
//         temp = head;
//         while(temp != nullptr && i<arr.size()){
//             temp->val = arr[i];
//             i++;
//             temp = temp->next;
//         }
//         return head;
//     }
// };


//OPTIMISED SOLUTION:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }
        ListNode* odd = head;
        ListNode*even = head->next;
        ListNode*evenHead = head->next;
        while(even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next; // hmne odd->next isiliye likha kuki hum odd->next ko alrdy point krva chuke hai
            even = even->next;
    }
        odd->next = evenHead;
        return head;
    }
};