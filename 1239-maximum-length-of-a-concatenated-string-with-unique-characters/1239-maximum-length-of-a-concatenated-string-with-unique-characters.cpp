class Solution {
private:
    bool distinct(string s){
        unordered_set<char> st;
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(st.find(c)!=st.end()){
                return false;
            }
            
            st.insert(c);
        }
        
        return true;
    }
    bool distinct(string s1, string s2){
        unordered_set<char> st;
        for(int i = 0; i<s1.size(); i++){
            char c = s1[i];
            st.insert(c);
        }
        
        
        for(int i = 0; i<s2.size(); i++){
            if(st.find(s2[i])!=st.end())
                return false;
        }
        return true;
    }
public:
    int memo[17];
    int solve(int idx, int n, string temp, vector<string>&arr){
        if(idx >= n){
            return temp.size();
        }
        
        //if(memo[idx]!=-1)return memo[idx];
        
        string cur = arr[idx];
        int notTake = solve(idx+1,n, temp, arr);
        int take = 0;
        if(distinct(temp, cur)){
            take = solve(idx+1, n, temp+cur, arr);
        }
        
        return   max(take, notTake);
    }
    int maxLength(vector<string>& arr) {
        vector<string> dis;
        
        memset(memo, -1 , sizeof(memo));
        
        for(int i = 0; i<arr.size(); i++){
            if(distinct(arr[i])){
                dis.push_back(arr[i]);
            }
        }
        
        return solve(0, dis.size(), "", dis);
    }
};