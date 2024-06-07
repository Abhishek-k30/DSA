class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st;
        for(auto &it : dictionary){
            st.insert(it);
        }
        
       string ans="";
        for(int i=0; i<sentence.size(); i++){
             string cur="";
            bool found = false;
            for(int j=i; j<sentence.size(); j++){
                if(!found)
                    cur+=sentence[j];
                
                if(st.find(cur)!=st.end()){
                     found = true;
                }
                
                if(sentence[j]==' '){
                    i=j;
                    break;
                }
                
                if(j==sentence.size()-1)i=sentence.size();
                    
            }
            
            //cout<<i<<" "<<cur<<endl;
            
            if(ans.size()>0 && ans.back()!=' ')ans+=' ';
            ans+=cur;
            
            
        }
        
        //cout<<endl;
        return ans;
    }
};