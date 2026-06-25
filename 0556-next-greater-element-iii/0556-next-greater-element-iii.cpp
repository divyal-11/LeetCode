class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int size = s.size();

        int idx = -1;
        for(int i=size-2;i>=0;i--){
            if(s[i]<s[i+1]){
                idx = i;
                break;
            }
        }

        if(idx==-1) return -1;

        for(int i=size-1;i>=0;i--){
            if(s[i]>s[idx]){
                swap(s[i],s[idx]);
                break;
            }
        }

        reverse(s.begin()+idx+1,s.end());

        long long ans = stoll(s);

        if(ans>INT_MAX) return -1;

        return ans;
        



    }
};