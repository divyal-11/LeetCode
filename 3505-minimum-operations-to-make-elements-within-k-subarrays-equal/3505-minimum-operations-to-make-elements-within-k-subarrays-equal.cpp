
class Solution {
public:
    multiset<int> lo, hi;
    long long sumLo = 0, sumHi = 0;

    void balance() {
        while (lo.size() > hi.size() + 1) {
            int v = *lo.rbegin();
            lo.erase(prev(lo.end()));
            sumLo -= v;
            hi.insert(v);
            sumHi += v;
        }

        while (lo.size() < hi.size()) {
            int v = *hi.begin();
            hi.erase(hi.begin());
            sumHi -= v;
            lo.insert(v);
            sumLo += v;
        }
    }

    void add(int v) {
        if (lo.empty() || v <= *lo.rbegin()) {
            lo.insert(v);
            sumLo += v;
        } else {
            hi.insert(v);
            sumHi += v;
        }
        balance();
    }

    void remove(int v) {
        auto it = lo.find(v);

        if (it != lo.end()) {
            lo.erase(it);
            sumLo -= v;
        } else {
            it = hi.find(v);
            hi.erase(it);
            sumHi -= v;
        }

        balance();
    }

    long long cost() {
        long long med = *lo.rbegin();

        return med * (long long)lo.size() - sumLo
             + sumHi - med * (long long)hi.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> costs(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        costs[0] = cost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            costs[i - x + 1] = cost();
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;

        for (int t = 1; t <= k; t++) {
            for (int i = 1; i <= n; i++) {
                dp[t][i] = dp[t][i - 1];

                if (i >= x && dp[t - 1][i - x] != INF) {
                    dp[t][i] = min(
                        dp[t][i],
                        dp[t - 1][i - x] + costs[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
