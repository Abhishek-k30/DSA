class Solution {
public:
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         map<int, int> m;
        for(auto &it: arr1)
            m[it]++;
        
        vector<int> ans;
        
        for(auto &it : arr2){
            int rep = m[it];
            
            for(int i=0; i<rep; i++)
                ans.push_back(it);
            
            m.erase(it);
        }
        
        
        for(auto &it: m ){
            int rep = it.second;
            
            for(int j=0; j<rep; j++)
                ans.push_back(it.first);
        }
        
        return ans;
       
    }
};