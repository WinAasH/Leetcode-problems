class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurance(26, -1);
        int ns = s.size();
        int i;
		// finding last occurance of all chars in string s
        for (i = 0; i < ns; i++) {
            lastOccurance[s[i] - 'a'] = i;
        }
        i = 0;
        int end = 0;
        vector<int> ans;
        int start = i;
        while (i < ns) {
			// updating end of partition till we find the last match of cur char
            end = max(lastOccurance[s[i] - 'a'], end);
            if (i == end) { 
                ans.push_back(end - start + 1);
                start = i + 1; // 
            }
            i++;
        }
        
        return ans;
    }
};