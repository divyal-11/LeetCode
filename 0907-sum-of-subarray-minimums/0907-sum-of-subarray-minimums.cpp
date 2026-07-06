class Solution {
public:
    vector<int> pse(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nse(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> prev = pse(arr);
        vector<int> next = nse(arr);

        long long ans = 0;

        for(int i=0;i<n;i++){
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + (1LL * arr[i] * left * right) % MOD) % MOD;
        }
        return ans;
        
        

    

    }
};
// int n = arr.size();
    // int ans = 0;

    // for (int i = 0; i < n; i++) {
    //     int mini = arr[i];
    //     for (int j = i; j < n; j++) {
    //         mini = min(mini, arr[j]);
    //         ans += mini;
    //     }
    // }
    // return ans;