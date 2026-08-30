class Solution {
public:
    
    void solve(int idx,string digits,string curr,vector<string>& ans){

        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }

        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        int digit = digits[idx] - '0';

        for(char ch:mp[digit]){
            curr.push_back(ch); //choose
            solve(idx+1,digits,curr,ans);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.empty()) return ans;
        solve(0,digits,"",ans);
        return ans;
    }
};