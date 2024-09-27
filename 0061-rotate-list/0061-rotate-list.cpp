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
    ListNode* findNthNode(ListNode* &head,int k){
        ListNode* temp = head;
        int cnt = 1;
        while(temp!=nullptr){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k==0){
            return head;
        } 
        ListNode*temp = head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            len++;
        }
        if(k%len == 0) return head;
         //if k is the multiple of len then after k rotations we will get the same original LL so we will simply return the LL
        k = k%len;
        tail->next = head;
        ListNode* newLastNode = findNthNode(head, len-k);
        head = newLastNode->next;
        newLastNode->next = nullptr;
        return head;
    }
};