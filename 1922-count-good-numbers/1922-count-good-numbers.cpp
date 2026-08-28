class Solution {
public:
    long long pow(long long base,long long exp){
        long long MOD = 1e9 + 7;
        long long res = 1;

        while(exp>0){
            if(exp%2==1){
                res = (res*base)%MOD;
            }
            base = (base*base)% MOD;
            exp = exp/2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return(pow(5,even)*pow(4,odd))%1000000007;
    }
};