class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char>st;
        int i  = 0;
        while(i<n){
            char temp = expression[i];
            if(temp == '|' || temp == '&' || temp == '('|| temp == 't' || temp == 'f' || temp == '!'){
                st.push(temp);
            }
            else if(temp == ')'){
                vector<char>cur;
                while(st.top() != '('){
                    cur.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char top = st.top();
                st.pop();
                if(top == '|'){
                    bool result =false;
                    for(char ch : cur){
                        if(ch == 't'){
                            result = true;
                            break;
                        }
                    }
                    st.push(result ? 't' : 'f');
                }

                else if(top == '&'){
                    bool result = true;
                    for(char ch:cur){
                        if(ch == 'f'){
                            result = false;
                            break;
                        }
                    }
                    st.push(result ? 't':'f');
                }

                else if(top == '!'){
                    st.push(cur[0] == 't' ? 'f':'t');
                }
            }
            i++;
        }
        return st.top() == 't';
    }
};