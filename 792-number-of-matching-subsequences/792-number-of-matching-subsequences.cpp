class Solution 
{
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count=0, N=s.length(), total_words=words.size();
        vector<vector<int>> vec(26);
        for(int i=0; i<N; i++)
        {
            vec[s[i]-'a'].push_back(i);
        }
        for(int i=0; i<total_words; i++)
        {
            bool found=true;
            int prev= -1;
            for(int j=0; found  &&  j<(words[i].length()); j++)
            {
                auto &v= vec[words[i][j] - 'a'];
                auto it= upper_bound(v.begin(), v.end(), prev);
                if(it==v.end())
                {
                    found= false;
                }
                else
                {
                    prev= *it;
                }
            }
            count+= found;
        }
        return count;
    }
};