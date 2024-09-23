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
    void InsertionSort(vector<int>&arr){
        for(int i=1; i<arr.size();i++){
            int key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode*temp = head;
        vector<int>arr;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        InsertionSort(arr);
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