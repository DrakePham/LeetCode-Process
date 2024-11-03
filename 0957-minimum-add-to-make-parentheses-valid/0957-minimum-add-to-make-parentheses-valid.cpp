class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                result--;
                st.pop();
                continue;
            }
            st.push(s[i]);
            result++;
        }
        return result;
    }
};