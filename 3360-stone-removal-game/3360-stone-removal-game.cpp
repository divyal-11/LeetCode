class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        
        int remove = 10;
        int turn  = 0;

        while(n>= remove){
            n -= remove;
            remove --;
            turn ++;
        }
        
        return (turn%2) == 1;


        
    }
};