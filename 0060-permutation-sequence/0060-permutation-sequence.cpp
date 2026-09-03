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
        int grp = (k - 1) / factorial(n - 1);
        ans += numbers[grp];
        numbers.erase(grp, 1);

        k = (k - 1) % factorial(n - 1)+1;
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