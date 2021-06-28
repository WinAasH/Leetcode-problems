class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int sz= size(digits);
        if(digits[sz-1]!=9)
        {
            digits[sz-1]= digits[sz-1]+1;
            return digits;
        }
        vector<int> res;
        int i=(sz-1);
        while(i>=0  &&  digits[i]==9)
        {
            digits[i]= 0;
            i--;
        }
        if(i==-1)
        {
            res.push_back(1);
            for(int it: digits)
            {
                res.push_back(it);
            }
        }
        else
        {
            digits[i]= digits[i]+1;
            for(int it: digits)
            {
                res.push_back(it);
            }
        }
        return res;
    }
};