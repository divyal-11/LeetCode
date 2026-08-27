class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121,0);

        for(int age:ages) cnt[age]++;
        int ans = 0;

        for(int i=1;i<121;i++){
            for(int j=1;j<121;j++){
                if(j > 0.5*i+7 && j<= i){
                    ans += cnt[i]*cnt[j];

                    if(i==j) ans-=cnt[i];
                }    
            }
        }
        return ans;

    }
};