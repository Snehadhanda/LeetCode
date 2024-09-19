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
class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        ListNode*temp = head;
        while(temp!=nullptr){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp = head;
        ListNode*tail = head;
        int len = length(head);
        int pos = 1;
        while(pos<k){
            temp = temp->next;
            pos++;
        }
        pos = 1;
        int bac_pos = len-k +1;
        while(pos < bac_pos){
            tail = tail->next;
            pos++;
        }
        int value = temp->val;
        temp->val = tail->val;
        tail->val = value;
        return head;
    }
};