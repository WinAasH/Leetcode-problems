class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int count=0, last=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==' ')
            {
                if(i>0  &&  s[i-1]!=' ')
                {
                    last= count;
                }
                count=0;
            }
            else
            {
                count++;
            }
        }
        if(count!=0)
        {
            last= count;
        }
        return last;
    }
};