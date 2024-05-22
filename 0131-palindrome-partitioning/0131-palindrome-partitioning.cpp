class Solution {
public:
    bool check(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    void dfs(int index, string &s, vector<string> &temp, vector<vector<string>> &ans){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(check(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                dfs(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string> temp;
       dfs(0, s, temp, ans);

       return ans;

    }
};