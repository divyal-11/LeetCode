class Solution {
public:
    int minimumDeletions(string s) {
        int del = 0;
        int bcnt = 0;

        for(char c: s){
            if(c == 'b') bcnt++;
            else del = min(bcnt, del+1);
        }
        return del;
    }
};