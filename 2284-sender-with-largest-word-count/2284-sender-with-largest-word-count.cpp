class Solution {
public:
    int wordCnt(string s){
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ')cnt++;
        }
        
        return cnt+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=messages.size();
        unordered_map<string, int> m;
        for(int i=0; i<n; i++){
            int count= wordCnt(messages[i]);
            m[senders[i]]+=count;
        }
        vector<pair<int, string>> vp;
        for(auto it: m){
            vp.push_back({it.second, it.first});
        }
        sort(vp.begin(), vp.end());
        return vp.back().second;
    }
};