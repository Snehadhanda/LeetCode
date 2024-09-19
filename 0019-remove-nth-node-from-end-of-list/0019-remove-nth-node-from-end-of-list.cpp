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
    int length(ListNode*head){
        int len = 0;
        ListNode*temp = head;
        while(temp!=nullptr){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
        int len = length(head);
        int bac_pos = len-n+1;
        if(bac_pos == 1){
            ListNode*temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode*prev = nullptr;
        ListNode*curr = head;
        int pos = 1;
        while(pos<bac_pos){
            prev = curr;
            curr = curr->next;
            pos++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        return head;
    }
};