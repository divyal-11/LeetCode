class Solution {
public:
    void combination(int idx,vector<int>& candidates,int target,vector<int>& curr,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i< candidates.size(); i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;//avoid duplicates at same level

            if(candidates[i]>target) break;

            curr.push_back(candidates[i]);
            combination(i+1,candidates,target-candidates[i],curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        combination(0,candidates,target,curr,ans);
        return ans;
    }
};