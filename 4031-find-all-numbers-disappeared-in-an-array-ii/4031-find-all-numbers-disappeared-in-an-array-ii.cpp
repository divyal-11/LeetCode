class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int num:nums){
            if(num<lower) continue;
            if(num>upper) break;

            if(num>lower) ans.push_back({lower,num-1});
            lower = num+1;
        }
        if(lower<=upper) ans.push_back({lower,upper});
        return ans;
    }
};