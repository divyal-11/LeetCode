class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;

    bool ispalindrome(string &s,int left,int right){
        while(left<=right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(int idx,string &s){
        if(idx==s.size()) {
            res.push_back(path);
            return;
        }

        for(int i=idx ; i<s.size();i++){
            if(ispalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return res;
    }
};