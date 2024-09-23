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
    // void sort(ListNode* &curr, ListNode* &nextNode){
    //     while(nextNode != nullptr){
    //         if(curr->val == nextNode->val){
    //             swap(curr, nextNode);
    //             curr = nextNode;
    //             nextNode = nextNode->next;
    //         }
    //         sort(nextNode,nextNode->next);
    //     }
    // }
    ListNode* sortList(ListNode* head) {
        // ListNode*curr = head;
        // ListNode*nextNode = head->next;
        // sort(curr, nextNode);
        // return head;
        ListNode*temp = head;
        vector<int>arr;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        int i=0;
        while(temp!=nullptr && i<arr.size()){
            temp->val = arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};