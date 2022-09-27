class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<pair<char, int>> rl;
        int pos= 0, n= dominoes.size();
        rl.push_back({'L', -1});
        for(int i=0; i<n; i++){
            if(dominoes[i]!='.'){
                rl.push_back({dominoes[i], i});
            }
        }
        rl.push_back({'R', n});
        for(int i=0; i<rl.size()-1; ++i){
            int start= rl[i].second, end= rl[i+1].second;
            char startc= rl[i].first, endc= rl[i+1].first;
            if(startc==endc){
                for(int j= start+1; j<end; ++j){
                    dominoes[j]= startc;
                }
            }
            else if(startc>endc){
                for(int j= start+1; j<end; ++j){
                    if(j-start== end-j){
                        dominoes[j]= '.';
                    }
                    else{
                        if(j-start< end-j){
                            dominoes[j]= 'R';
                        }
                        else{
                            dominoes[j]= 'L';
                        }
                    }
                }
            }
        }
        return dominoes;
    }
};