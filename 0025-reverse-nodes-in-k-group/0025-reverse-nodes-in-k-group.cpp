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
//isme hame k ke group me LL ko reverse krna hai....toh hum isme ek case ko solve kr denge....baki recursion ke upr chd denge
//lkin jhan glti hoti hai ki jo hmne solve kra ek part .....or jo baki ka bacha hua recursion ne kra....un dono ko connect kaise kre ge
//head->next = recurkaAns kr denge
class Solution {
public:
    int length(ListNode*head){
        ListNode*temp = head;
        int len =0;
        while(temp!=nullptr){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode*prev = nullptr;
        ListNode*curr = head;
        int pos = 0;
        ListNode*nextNode = curr->next;
        int len = length(head);
        if(len<k){
            return head;
        }
        while(pos < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }
        ListNode*recurAns = nullptr;
        if(nextNode != nullptr){
            recurAns = reverseKGroup(nextNode, k);
            head->next = recurAns;
        }      
        return prev;
    }
};