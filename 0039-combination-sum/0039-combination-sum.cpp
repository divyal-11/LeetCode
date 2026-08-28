class Solution {
public:
    void combination(int idx,vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& ans){
         

        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }

        //take
        if(candidates[idx] <= target){
            curr.push_back(candidates[idx]);

            combination(idx,candidates,target-candidates[idx],curr,ans);

            curr.pop_back();
        }

        //not take
        combination(idx+1,candidates,target,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        combination(0,candidates,target,curr,ans);
        return ans;
    }
};