class Solution {
private:
    void findPath(vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &path, int curr){
        path.push_back(curr);
        if(curr  ==  graph.size()-1) res.push_back(path);
        else    for(int it: graph[curr]) findPath(graph, res, path, it);
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        findPath(graph, res, path, 0);
        return res;
    }
};