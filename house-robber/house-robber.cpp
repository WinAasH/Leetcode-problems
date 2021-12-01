class Solution {
public:
    int rob(vector<int>& nums) {        
        
        // Simple edge cases
        if ( nums.size() == 1 ) return nums[0];
        if ( nums.size() == 2 ) return max( nums[0], nums[1] );
                
        // ante2:
        // amount of money for the best robbery 2 houses before current position
        int ante2 = nums[0];
        
        // ante:
        // amount of money for the best robbery 1 house before current position (adjacent)
        int ante = max( nums[0], nums[1] );
        
        // best:
        // best overall robbery
        int best = 0;
        
        // iterate from the 3rd house
        for ( int i = 2; i < nums.size(); ++i ) 
        {
            // best robbery = max between:
            //    - robbery from the previous adjacent house
            //    - robbery from this house + 2 houses before
            best = max( ante, nums[i] + ante2 );
            
            // Advance to the next house
            // - the adjacent previous house becomes the one 2 houses before
            ante2 = ante;
            // - the best robbery for the adjacent house is updated witht the new robbery
            ante = max( ante, best );
        }
        
        return best;
    }
};