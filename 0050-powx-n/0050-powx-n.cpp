class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        
        if(n<0){
            x = 1/x;  //jb bhi oower negative hogi toh hume base 1/base krna hota hai
            if(n==INT_MIN){ // The special case for n == INT_MIN is handled separately to prevent integer overflow when negating n.
                return x*pow(x,-(n+1));
            }
            n=-n;  //ab humne x ko 1/x kr lia hai toh isiliye -ve power ko +ve me bdl denge
        }
        double ans = myPow(x,n/2);
        ans *=ans;
        if(n%2 ==1) ans*=x;
        
        return ans;
    }
};