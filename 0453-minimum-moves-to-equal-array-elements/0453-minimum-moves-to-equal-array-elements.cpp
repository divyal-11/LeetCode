class Solution {
public:
    int minMoves(vector<int>& nums) {
     int n = nums.size(), moves =0;
     int mini = INT_MAX;

     for(int i=0;i<n;i++) mini = min(mini,nums[i]);
     for(int i=0;i<n;i++) moves += (nums[i]-mini);

     return moves;
    }
    
};

