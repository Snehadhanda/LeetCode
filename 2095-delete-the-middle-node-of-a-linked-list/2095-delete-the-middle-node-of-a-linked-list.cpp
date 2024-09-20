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
    int Length(ListNode* head){
        int len = 0;
        ListNode*temp = head;
        while(temp !=nullptr){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*prev = nullptr;
        ListNode*curr = head;
        int i=0;
        int n = Length(head);
        int len = n/2;
        if(len == 0){
            ListNode*temp = head;
            delete temp;
            return nullptr;
        }
        while(i<len){
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        return head;
    }
};