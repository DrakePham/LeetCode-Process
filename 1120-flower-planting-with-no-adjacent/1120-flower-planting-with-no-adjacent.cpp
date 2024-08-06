class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> gardent;
        vector<bool> visited (n + 1, false);

        for(auto& path:paths){
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);

        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i, graph, gardent, visited);
            }
        }
        vector<int> result;
        for(int i = 1; i <= n; i++){
            result.push_back(gardent[i]);
        }
        return result;

    }
    void dfs(int curNode, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& gardent, vector<bool>& visited){
        if(visited[curNode]) return;
        visited[curNode] = true;
        unordered_set<int> set;
        for(auto& node:graph[curNode]){
            if(gardent[node]){ set.insert(gardent[node]);};
        }
        int flower = 1;
        while(set.find(flower) != set.end()){
            flower++;
        }
        gardent[curNode] = flower;

        for(auto& node:graph[curNode]){
            dfs(node, graph, gardent, visited);
        }

    }
};