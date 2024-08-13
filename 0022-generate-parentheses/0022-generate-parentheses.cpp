class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curPath = "";
        helper(n , n, curPath, result);
        return result;
    }
    
    void helper(int O, int C, string curPath, vector<string>& result){
        if(C < O || O == -1 || C == -1) return;
        if(C == 0 and O == 0){
            result.push_back(curPath);
            return;
        }
        string curPath1 = curPath + '(';
        helper(O - 1, C, curPath1, result);
        string curPath2 = curPath + ')';
        helper(O, C - 1, curPath2, result);
    }
};