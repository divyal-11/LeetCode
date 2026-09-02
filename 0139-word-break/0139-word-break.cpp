class Solution {
public:

    vector<int> dp;

    bool dfs(int idx, string& s, vector<string>& wordDict) {

        if(idx == s.size())
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        for(int i = idx; i < s.size(); i++) {

            string word = s.substr(idx, i - idx + 1);

            if(find(wordDict.begin(), wordDict.end(), word)
               != wordDict.end()) {

                if(dfs(i + 1, s, wordDict))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        dp.resize(s.size(), -1);

        return dfs(0, s, wordDict);
    }
};