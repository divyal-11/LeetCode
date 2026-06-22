class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp1,mp2;
        for(char c:s) mp1[c]++;
        for(char c:target) mp2[c]++;

        int ans = INT_MAX;
        for(auto &[ch,freq]:mp2)
            ans = min(ans,mp1[ch]/freq);

        return ans;
    }
};