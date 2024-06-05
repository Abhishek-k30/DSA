class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0; i<words[0].size(); i++){
            char c = words[0][i];
            string p = "";
            p+=c;
            bool f = true;
            for(int j = 1; j<n; j++){
                string mat = words[j];
                bool found = false;
                for(int k = 0; k<mat.size(); k++){
                    if(c==mat[k]){
                        words[j][k] = '#';
                        found=true;
                        break;
                    }
                }
                if(!found)
                    f= false;
            }
            
            if(f)
                ans.push_back(p);  
            
        }
        
        return ans;
    }
};