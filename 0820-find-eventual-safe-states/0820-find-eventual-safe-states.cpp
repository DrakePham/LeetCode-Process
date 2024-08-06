class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int i, j, n = graph.size(), m = graph[0].size();
	
    vector<int> res;
	vector<int> in(n, 0);
    vector<vector<int>> deg(n, vector<int>());
	
    queue<int> q;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < graph[i].size(); j++) {
            
            deg[graph[i][j]].push_back(i); 
            in[i]++;
            
        }
    }
    
    for (i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
            cout << i << " ";
        }
    }
    
    while (!q.empty()) {
        i = q.front();
        q.pop();
        res.push_back(i);
        for (auto c: deg[i]) {
            in[c]--;
            
            if (in[c] == 0) q.push(c);
        }
    }
    
    sort(res.begin(), res.end());
    
    return res;
    }
};