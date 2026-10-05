class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);
        for(char c : s){
            if(c == '('){
                st.push(0);
            }
            else{
                int current = st.top();
                st.pop();

                if(current == 0){
                    st.top() += 1;
                }
                else{
                    st.top() += 2*current;
                }
            }
        }
    return st.top();

    }
};