class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int x : nums)
            freq[x]++;
        for (int x : target)
            freq[x]--;
        for (auto i : freq)
            if (i.second != 0)
                return 0;


        int mismatch = n;

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                mismatch = i;
                break;
            }
        }

        vector<int> temp = nums;

        sort(temp.begin()+mismatch, temp.end());
        reverse(temp.begin()+mismatch, temp.end());


        if(temp!=target) return 0;

        int ans = (mismatch!=n), maxi = INT_MIN;

        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,nums[i]);

            if(i < mismatch){
                if(maxi== temp[i]) ans++;
                else break;
            }


        }
        return ans;
    }
};