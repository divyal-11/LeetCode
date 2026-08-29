class Solution {
public:
    void combinations(int idx,int k,int target,vector<int>& curr,vector<vector<int>>& ans){

        if(curr.size()==k){
            if(target==0) ans.push_back(curr);
            return;
        }

        for(int i=idx;i<=9;i++){

            if(i > target) break;
            
            curr.push_back(i);

            combinations(i+1,k,target-i,curr,ans);

            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        combinations(1,k,n,curr,ans);
        return ans;
    }
};