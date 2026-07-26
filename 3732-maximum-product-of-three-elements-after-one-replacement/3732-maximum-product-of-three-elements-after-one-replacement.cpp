class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long m = 100000;
        long long mn = -100000;
        long long a = nums[0];
        long long b = nums[1];
        long long c = nums[n-1];
        long long d = nums[n-2];

        return max(
            {a*b*m,
            c*d*m,
            a*c*mn}
        );
    }
};