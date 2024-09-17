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
        ListNode*temp= head;
        int cnt =0;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int n = Length(head);
        int pos = n/2 + 1;
        int i=1;
        ListNode* temp = head;
        while(i != pos){
            temp = temp->next;
            i++;
        }
        return temp;
    }
};