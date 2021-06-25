class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(size(digits)==0)
        {
            return res;
        }
        map<int, vector<string>> m;
        m[2]= {"a", "b", "c"};
        m[3]= {"d", "e", "f"};
        m[4]= {"g", "h", "i"};
        m[5]= {"j", "k", "l"};
        m[6]= {"m", "n", "o"};
        m[7]= {"p", "q", "r", "s"};
        m[8]= {"t", "u", "v"};
        m[9]= {"w", "x", "y", "z"};
        int len= size(digits);
        int i=0;
        queue<string> q;
        while(i<len)
        {
            int j= q.size();
            if(j!=0)
            {
                while(j>0)
                {
                    string temp= q.front();
                    q.pop();
                    vector<string> vec= m[digits[i]- '0'];
                    for(string it: vec)
                    {
                        q.push(temp+it);
                    }
                    j--;
                }
            }
            else
            {
                vector<string> vec= m[digits[i]- '0'];
                for(string it: vec)
                {
                    q.push(it);
                }
            }
            i++;
        }
        while(!q.empty())
        {
            string temp= q.front();
            q.pop();
            res.push_back(temp);
        }
        return res;
    }
};