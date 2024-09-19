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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next==nullptr) return head;
        int pos = 0;
        ListNode*prev = nullptr;
        ListNode*curr = head;
        ListNode*nextNode = curr->next;
        while(pos < 2){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }
        ListNode*recurAns = nullptr;
        if(nextNode != nullptr){
            recurAns = swapPairs(nextNode);
            head->next = recurAns;
        }
        return prev;
    }
};