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
    ListNode* midLL(ListNode* &slow, ListNode* &fast){  
        while(fast->next != nullptr){
            fast = fast->next;
            if(fast->next != nullptr){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode*reverse(ListNode* &prev, ListNode* &curr){
        while(curr != nullptr){
            ListNode*nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    bool CompareList(ListNode* &head, ListNode* &head2){
        while(head !=nullptr && head2 !=nullptr){
            if(head->val != head2->val){   //yhan pe data ki jagh val nam ka variable dia hai
                return false;
            }
            else{
                head = head->next;
                head2 = head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 2 parts me break kre ge
        ListNode*midNode = midLL(slow,fast);
        ListNode* head2 = midNode->next;
        midNode->next = nullptr;
        // 2nd half ko reverse kre ge
        ListNode* prev = nullptr;
        ListNode* curr = head2;
        head2 = reverse(prev,curr);
        // dono ko compare kre ge
        bool ans = CompareList(head,head2);
        return ans;
    }
};