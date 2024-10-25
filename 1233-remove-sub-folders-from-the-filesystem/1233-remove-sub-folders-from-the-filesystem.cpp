class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_set<string> st;
        vector<string> ans;
        for(auto &it : folder){
            string s = "";
            bool flag = true;
            for(char c : it){ 
                    if(c=='/'){
                        if(st.find(s)!=st.end()){
                            flag = false;
                            break;
                        }
                    }
                    s+=c; 
                
            }
            if(flag){
                st.insert(s);
                ans.push_back(s);
            }
        }
        
        
        
        return ans;
    }
};