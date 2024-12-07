// class Solution {
// public:
//     bool isPalindrome(int x) {
//         using LL = long long;
//         if (x < 0)  return false;

//         LL reversed = 0, temp = x;

//         while (temp != 0) {
//             int digit = temp % 10;
//             reversed = reversed * 10 + digit;
//             temp /= 10;
//         }

//         return (reversed == x);
//     }
        
// };


class Solution {
public:
    bool isPalindrome(int x) {
        using LL = long long;
        LL revNum=0;
        LL temp = x;
        while(x>0){
            LL ld = x % 10;
            revNum = (revNum*10) + ld;
            x=x/10; 
        }
        if(revNum==temp) return true;
        else return false;
    }
        
};