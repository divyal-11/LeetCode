
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // Available: {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;

        // Busy: {finishTime, weight, index}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > busy;

        int n = servers.size();

        // Initially, all servers are available
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long currentTime = 0;

        for (int i = 0; i < tasks.size(); i++) {

            // Task i arrives at time i
            currentTime = max(currentTime, (long long)i);

            // Move all finished servers to available heap
            while (!busy.empty() &&
                   get<0>(busy.top()) <= currentTime) {

                auto [finishTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait
            if (available.empty()) {

                currentTime = get<0>(busy.top());

                // Release all servers finishing by this time
                while (!busy.empty() &&
                       get<0>(busy.top()) <= currentTime) {

                    auto [finishTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans.push_back(index);

            // Calculate when this server becomes free
            long long finishTime = currentTime + tasks[i];

            busy.push({finishTime, weight, index});
        }

        return ans;
    }
};
