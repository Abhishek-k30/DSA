class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        map<string, int> m;
        int mx=0;
        for(int i=0; i<n; i++){
            m[words[i]]++;
            mx=max(mx, m[words[i]]);
        }
        priority_queue<pair<int, string>> pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }
        vector<string> ch;
        int ind=0;
        while(!pq.empty()){
            string s= pq.top().second;
            int freq=pq.top().first;
            pq.pop();
            if(freq<mx){
                sort(ch.begin()+ind, ch.end());
                ind=ch.size();
                mx=freq;
            }
            
            ch.push_back(s);
            
        }
        sort(ch.begin()+ind, ch.end());
        vector<string> ans;
        for(int i=0; i<k; i++){
            ans.push_back(ch[i]);
        }
        return ans;
    }
};