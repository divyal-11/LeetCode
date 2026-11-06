class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs according to time
        sort(logs.begin(), logs.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        // Store queries with their original indices
        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        // Sort queries according to time
        sort(q.begin(), q.end());

        unordered_map<int, int> mp;
        vector<int> ans(queries.size());

        int l = 0, r = 0;
        int m = logs.size();

        for (auto [time, idx] : q) {

            // Add logs within the right boundary
            while (r < m && logs[r][1] <= time) {
                mp[logs[r][0]]++;
                r++;
            }

            // Remove logs outside the left boundary
            while (l < r && logs[l][1] < time - x) {
                mp[logs[l][0]]--;

                if (mp[logs[l][0]] == 0) {
                    mp.erase(logs[l][0]);
                }

                l++;
            }

            // Servers with zero requests
            ans[idx] = n - mp.size();
        }

        return ans;
    }
};