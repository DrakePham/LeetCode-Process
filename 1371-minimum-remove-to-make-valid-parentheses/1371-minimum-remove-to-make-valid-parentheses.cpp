class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        int length = s.length();
        for(int i = 0 ; i < length; i++){
            char ch = s[i];
            if(!st.empty() && st.top().first == '(' && ch == ')'){
                st.pop();
            }else if( ch == '(' || ch == ')'){
                st.push({ch, i});
            }
        }
        string result = "";
        for(int i = length - 1; i >= 0; i--){
            int removeIndex = (!st.empty()) ? st.top().second : -1;
            if(removeIndex == i){
                st.pop();
                continue;
            }
            result += s[i];
        }
        reverse(result.begin(), result.end());

        return result;

    }
};



// ()


// )(


// ( or ) -> return ""
// () return ()
// ab( or ab) return ab
// (ab or )ab return ab
// a(b or a)b return ab

// not stack not empty, top = (, have ) -> pop
// not stack not empty, top = (, have ) -> pop

// (.... | ).... -> index + 1, s.end()
// ....)  | ....( -> 0, s.end() - 1
// ....(.... || ....).... -> 0 , index + index + 1 , s.end()
// ( | ) -> 0, index - 1