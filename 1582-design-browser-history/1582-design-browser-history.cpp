class BrowserHistory {
public:
    vector<string> history;
    int currentIndex = 0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        int lengthOfHistory = history.size();
        if(lengthOfHistory - 1 > currentIndex){
            history.erase(history.begin() + currentIndex + 1, history.end());
        }
        history.push_back(url);
        currentIndex = history.size() - 1;
    }
    
    string back(int steps) {
        currentIndex = (currentIndex - steps >= 0)  ? currentIndex - steps : 0;
        // cout<<currentIndex<<endl;
        return history[currentIndex];
    }
    
    string forward(int steps) {
        int finalIndex = history.size() - 1;
        currentIndex = (currentIndex + steps <= finalIndex)  ? currentIndex + steps : finalIndex;
        return history[currentIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */