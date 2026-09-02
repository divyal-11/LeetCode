class Solution {
public:
    vector<string> ans;
    void dfs(string& num,int target,int idx,string expr,long long curval,long long prevop){
        if(idx == num.size()){
            if(curval==target) ans.push_back(expr);
            return;
        }

        for(int i=idx;i<num.size();i++){

            if(i>idx && num[idx]=='0') break;

            string part = num.substr(idx,i-idx+1);
            long long cur = stoll(part);

            if(idx == 0){
                dfs(num,target,i+1,part,cur,cur);
            }
            else{
                dfs(num,target,i+1,expr + '+'+part, curval+cur,cur);
                dfs(num,target,i+1,expr + '-'+part, curval-cur,-cur);
                dfs(num,target,i+1,expr + '*'+part, curval - prevop + prevop*cur, prevop*cur);
            }

        }
    }
    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, "", 0, 0);
        return ans;
    }
};