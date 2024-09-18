/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//approach: SLOW AND FAST ALGO
//isme hame starting point of loop nikalna hai
//s-1) phle chck kro loop hai ya nhi(if fast==slow means loop is present)
//s-2) if loop is present then set slow = head;
//s-3) move slow and fast by 1 step

//WHY THIS ALGO WORKS: iski puri ek algo hai
/*
distance travelled by fast = 2*dist travelled by slow

let A = dist travelled by fast/slow upto begin of loop
kC = kuch no. of cycles jo fast/slow traverse kre ge until they meet
B = begin of node se us node tk ka distance jhan dono meet kre ge
EXPRESSIONS BECOME: 
                    A+ k1C +B = 2*[A+K2C+B]
                    K1C-k2C = A+B
                    (K1-K2)C = A+B
                    KC = A+B
                    A = KC-B
Now jb slow =head ho jayega....toh slow toh A dist travel kre ga (begin of node tk aane me)
fast will travel: kuch no. of cycle + (C-B).....aaisa isiliye hume begin tb mille ga jb fast or slow dono meet kr jayege.....lkin possibility hai ki fast jo hai vo slow se phle begining node pe punch jaye...tb fast apna cycle complete kre ga.....isiliye fast will travel kuch No of cycle +(C-B)
Let Kuch no of cycle of fast be xC
                    XC + C-B
                    (X+1)C-B
                    KC-B .....(kuch no of cycle-B)
                    A    (upr we have alrdy proved that kuch no of cycle-B = A)
                    is se hum bol sktey hai ki jo ye part tha slow or fast same distance travel kre ge
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast = head;
        ListNode*slow = head;
        while(fast != nullptr){
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast==slow){
                //mtlb cycle present hai toh break kr jayege
                break;
            }
        }
        if(fast == nullptr) return nullptr;
        //mtlb yhan pe slow and fast meet kr chuke hai
        slow = head;
        while(fast !=slow){
            slow=slow->next;
            fast = fast->next;
        }
        
        //mtlb slow or fast dono meet kr gaye
        return slow;
    }
};