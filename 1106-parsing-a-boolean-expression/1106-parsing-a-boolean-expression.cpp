class Solution {
private:
    char solveOps(vector<char>&values, char ops){
        if(ops == '&'){
            for(auto &it: values){
                if(it == 'f'){
                    return 'f';
                }
            }
            return 't';
        }
        else if(ops == '|'){
            for(auto &it: values){
                if(it == 't'){
                    return 't';
                }
            }
            return 'f';
        }
        else {
            return (values[0]=='t')? 'f' : 't';
        }
    }
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        
        stack<char> st;
        
        for(int i = 0; i<n; i++){
            if(expression[i] == ','){
                continue;
            }
            else if(expression[i] == ')'){
                
                vector<char> values;
                
                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
                
                char ops = st.top();
                
                st.pop();
                
                char res = solveOps(values, ops);
                
                
                st.push(res);
            }
            else st.push(expression[i]);
        }
        
        
        return (st.top() == 't' ? true : false);
    }
};
// TC = O(n), SC = O(n)