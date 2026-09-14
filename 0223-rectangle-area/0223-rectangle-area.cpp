class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ax2-ax1)*(ay2-ay1);
        int a2 = (bx2-bx1)*(by2-by1);

        int wol = min(ax2,bx2) - max(ax1,bx1);
        int lol = min(ay2,by2) - max(ay1,by1);

        int overlap = 0;
        if(wol>0 && lol>0) overlap = wol*lol;

        return a1 + a2 -overlap;
    }
};