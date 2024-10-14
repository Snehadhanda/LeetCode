//brute force : har ek index pe check kre ge circle ban rha hai ya nhi
//optimised:
//intial index pe condition fulfil nhi ho rhi toh us index pe lagayege jhan pe condition break ho rhi hogi

//important logic:
//agar traversal ke time pe.....hum har ek index ki cost ko add krtey hue condition fulfil nhi kar paye....toh jb hum us se agle index se jb start kre ge toh direct us index se start kre ge jhan pe condition break kre gi.......kuki jb phle wale index ke sath hi condition fulfil nhi ho pa rhi thi toh uske bina toh gaurntee hai ki nhi kar payega fulfil....kuki isme sum hho rha tha har index pe....or 1st wale index ka kuch na kuch contributuion jrur hoga

//steps:
/* 
1). take 2 pointers front,rear...both at index 0
2).if movement possible(1 gas stat to another)....rear++;
3) if movement not possible then front = rear+1 and rear = front;
4) jab bhi fornt==rear ho jayega....mtlb circle complete ho jayega
//circle nhi mil paya toh return -1....kuki kopi bhi ans nhi hoga
*/


//METHOD 3:
/*
upr wale solution me optimization km hai kuki usme jin indexes pe alrdy gas or cost ko check kr rhe hai vo dubara krna pad rha hai

//is problem ka solution hai ki jhan jhan bhi fulfil nhi ho paa rha unko ek single gas station enitity man ke track rakh lenge...or jhan bhi track fulfil ho payega usko alg se ek single as an single entity track rakh lenge

jin bhi gas station pe gas-cost < 0 hoga(-ve hoga)....jitna km aayega usko hum "deficit" me store kr lenge
jin bhi gas station pe gas-cost>=0 hoga(+ve hoga)...jitna zyada aayega usko hum "balance" nam se store kr lenge

//agar balnce-deficit >= 0 ...means movement possible
//else movement not possible
//iske andr vo logic bhi aayega....ki jhan pe condition break kri hai uske next index se algi bar check kre ge
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        //index form where we are starting
        int start =0;
        
        //har ek index ko check krna hai ki vo answer hai ya nhi
        for(int i=0; i<gas.size(); i++){
            balance = balance + gas[i] - cost[i];
            if(balance < 0){
                deficit += abs(balance); //mtlb agar balance -ve ho gaya toh mtlb vo deficit hai
                start = i+1;
                balance =0;
            }
        }
        if(balance - deficit >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};