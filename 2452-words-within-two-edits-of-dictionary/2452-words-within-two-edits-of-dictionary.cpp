class Solution {
private:
    int check(string &a, string & b){
         int cnt = 0;
         for(int i=0; i<a.size(); i++){
             if(a[i]!= b[i])cnt++;
         }
        
        return cnt;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        int n = queries.size();
        int m = dict.size();
        
        vector<string> ans;
        
        for(int i=0; i<n; i++){
            string word= queries[i];
            int mnDiff = word.size();
            
            for(int j=0; j<m; j++){
                string match = dict[j];
                mnDiff= min(mnDiff, check(word, match));
            }
            
            if(mnDiff<=2)
                ans.push_back(word);
        }
        
        return ans;
    }
};