class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char, int> database = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int ans=database[s[s.size()-1]];
        for(int i=s.size()-2; i>=0; i--){
            
            if(database[s[i]]<database[s[i+1]]){
                ans-=database[s[i]];
            }
            else {
                ans+=database[s[i]];
            }
            
            
            
            
        }
        
        return ans;
    }
    
};