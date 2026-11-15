class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        int ans = 0;
        int sum = 0;
        int odd = 0, even = 1;

        for(int i:arr){
            sum += i;

            if(sum%2 == 1){
                ans = (ans + even)% MOD;
                odd++;
            }
            else{
                ans = (ans+odd) % MOD;
                even++;
            }
        }
        return ans;



    }
};