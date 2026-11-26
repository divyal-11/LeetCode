class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>> st;

        string ans = "";
        int num =0 ;

        for(char c:s){
            if(isdigit(c)) num = num*10 + (c - '0');

            else if(isalpha(c)) ans += c;

            else if(c == '['){
                st.push({ans,num});

                ans = "";
                num = 0;
            }

            else if(c == ']'){
                auto top = st.top();
                st.pop();

                string prev = top.first;
                int count = top.second;

                string temp = "";

                for(int i=0;i<count;i++){
                    temp += ans;
                }

                ans = prev + temp;
            }
        }
        return ans;
    }
};