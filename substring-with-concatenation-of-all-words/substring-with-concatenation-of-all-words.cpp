class Solution {
public:
    vector<int> findSubstring(string str, vector<string>& arr) {
        unordered_map<string, int> table;
        vector<int> ans;
        if(arr.size() == 0){
            return ans;
        }
        int word_len = arr[0].length();
        int window_len = arr.size()*word_len;
        for(string i : arr){
            table[i]++;
        }
        if(str.length() < window_len)
            return ans;

        unordered_map<string, int> ref(table);
        unordered_map<string, int>::iterator it;

        for (int i = 0; i < word_len;i++){
            int start = i, end = i;
            table = ref;
            int counter = table.size();

            while(end+word_len-1 < str.size()){
                string tmp = str.substr(end, word_len);

                if(table.count(tmp) == 1){
                    table[tmp]--;
                    if(table[tmp] == 0)
                        counter--;
                }

                while(counter == 0){
                    if(end-start+word_len == window_len){
                        ans.push_back(start);
                    }
                    string tmp1 = str.substr(start, word_len);
                    if(table.count(tmp1) ==1){
                        table[tmp1]++;
                        if(table[tmp1] > 0)
                            counter++;
                    }
                    start += word_len;
                }

                end += word_len;
            }
        }
        return ans;
    }
};