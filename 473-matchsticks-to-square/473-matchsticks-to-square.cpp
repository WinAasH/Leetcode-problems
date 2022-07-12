class Solution 
{
private:
    bool matches[16];
    bool isSquare(vector<int> &matchsticks, int currentSum, int sides, int totalSides, int idx= 0) 
    {
        if(totalSides== 0)
        {
            return true;
        }
        if(currentSum== sides)
        {
            return isSquare(matchsticks, 0, sides, totalSides-1, 0);
        }
        if(idx>=size(matchsticks))
        {
            return false;
        }
        for(int i= idx; i< size(matchsticks); i++) 
        {
            if (!matches[i]) 
            {
                if(currentSum+matchsticks[i] <= sides) 
                {
                    matches[i] = true;
                    if(isSquare(matchsticks, currentSum+matchsticks[i], sides, totalSides, i+1))
                    {
                        return true;
                    }
                    matches[i]= false;
                }
            }
        }
        return false;
    }
    
public:
    bool makesquare(vector<int> &matchsticks) 
    {
        sort(matchsticks.rbegin(), matchsticks.rend());
        memset(matches, false, sizeof(matches));
        int sum = 0;
        for(int i: matchsticks)
        {
            sum += i;
        }
        if(sum%4 != 0)
        {
            return false;
        }
        int sides= (sum/4);
        int totalSides= 4;
        return isSquare(matchsticks, 0, sides, totalSides);

    }
};