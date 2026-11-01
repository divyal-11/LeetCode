class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), moves = 0;
        nth_element(nums.begin(),nums.begin()+ (n/2),nums.end());

        int med = nums[n/2];

        for(int i=0;i<n;i++){
            moves += abs(nums[i] - med);
        }
        return moves;

    }
};