class Solution {
public:
    void combinations(int idx,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        ans.push_back(curr);

        for(int i=idx;i< nums.size();i++){
            curr.push_back(nums[i]); //take
            combinations(i+1,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        combinations(0,nums,curr,ans);
        return ans;

    }
};