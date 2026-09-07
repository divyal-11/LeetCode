class Solution {
public:
    string ans;
    string numbers;
    int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++)
            fact *= i;
        return fact;
    }
    void solve(int n, int& k) {
        int grpsize = factorial(n - 1);
        int grpnum = (k - 1) / grpsize;
        ans += numbers[grpnum];
        numbers.erase(grpnum, 1);

        k = (k -1) % factorial(n - 1) +1;
    }
    string getPermutation(int n, int k) {
        for (int i = 1; i <= n; i++) {
            numbers += to_string(i);
        }

        while (n > 0) {
            solve(n, k);
            n--;
        }

        return ans;
    }
};