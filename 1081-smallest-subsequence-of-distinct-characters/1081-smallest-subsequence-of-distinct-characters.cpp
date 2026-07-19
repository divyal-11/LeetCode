class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lstind(26,0);
        vector<bool> seen(26,false);
        stack<char> st;

        for(int i=0;i<s.size();i++) lstind[s[i]-'a'] = i;

        for(int i=0;i<s.size();i++){
            int curr = s[i] - 'a';
            if(seen[curr]) continue;

            while(!st.empty() && st.top()>s[i] && i<lstind[st.top()-'a']){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};