class Solution {
public:
int digits(int n){
    
    int product = 1;
    while(n>0){
        int digit = n%10;
        if(digit == 0){
            return 0;
        }
        product *= digit;
        n  = n/10;
    }
    return product;
}
    int smallestNumber(int n, int t) {
        while(true){
            int product = digits(n);
            if(product%t == 0){
                return n;
            }
            n++;
        }
    }
};