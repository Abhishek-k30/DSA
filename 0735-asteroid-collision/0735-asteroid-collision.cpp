class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> tot;
        stack<int> st;
        for(int i =0; i<n; i++){
            int cur = asteroids[i];
            
            if(cur<0 && st.empty())
                tot.push_back(cur);
            else if(cur>0)
                st.push(cur);
            else{
                while(!st.empty() && cur<0){
                    int up = st.top();
                    if(abs(cur)>abs(up)){
                        st.pop();
                        
                    }
                    else if(abs(cur)==abs(up)){
                        st.pop();
                        cur = 0;
                        break;
                    }
                        
                    else{
                        cur= st.top();
                        break;
                    }
                }
                if(st.empty() && cur<0)
                    tot.push_back(cur);
            }
        }
        
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        
        for(int i=temp.size()-1; i>=0 ; i--)
            tot.push_back(temp[i]);
        
        return tot;
    }
};