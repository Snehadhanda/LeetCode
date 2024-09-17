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
// class Solution {
// public:
//     int Length(ListNode* head){
//         ListNode*temp= head;
//         int cnt =0;
//         while(temp != nullptr){
//             cnt++;
//             temp = temp->next;
//         }
//         return cnt;
//     }
//     ListNode* middleNode(ListNode* head) {
//         int n = Length(head);
//         int pos = n/2 + 1;
//         int i=1;
//         ListNode* temp = head;
//         //method 1
//         // while(i != pos){
//         //     temp = temp->next;
//         //     i++;
//         // }
//         // method 2
//         while(pos != 1){
//             pos--;
//             temp = temp->next;
//         }
//         return temp;
//     }
// };

//METHOD 2 : SLOW & FAST APPROCH/  TORTOISE ALGORITHM
//ISKE ANDR SLOW WALA PTR 1 STEP MOVE KRTA HAI.....OR FAST WALA POINTER 2 STEP MOVE KRTA HAI
//slow wala pointer tabhi 1 step aage badh paye ga jb fast wala pointer ke pas 2 step aage badhne ki jgah ho
// simple shbdo me : agr do admi(slow and fast) sidhi chdh rhe hai....toh phle fast wala insan 2 sidhi chdhe ga uske bad slow wala insan 1 sidhi chdhe ga
//use case: LL me mid node nikalna etc.
//fast null tk ja skta hai.....mtlb aaisa case ho jhan pe 2 step lene pe null pe punch jayege toh vo valid hai

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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr){
            fast = fast->next; //yhan fast->next->next isiliye nhi kia kuki there is a posibility ki fast->next null ho or null->next will give error then...toh isiliye phle ek step aage badhe 
            if(fast != nullptr){
                //ek bar fast ko aage badhne ke bad chk kre ge ki fast null toh nhi hua....null nhi hoga toh hi aage badhe ge
                fast = fast->next;
                slow = slow->next;
            }
            
        }
        return slow;
    }
};