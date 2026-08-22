class Solution {
public:
    bool checkDivisibility(int n) {
        int k = n;
        int sum = 0;
        int product = 1;

        while(k>0){
            int m =  k%10;
            sum = sum+m;
            product = product*m;
            k = k/10;
        }
        int total = sum+product;
        if(n % total == 0){
            return true;
        }
        return false;
    }
};