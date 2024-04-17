class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i=0; i<wordDict.size(); i++)dict.insert(wordDict[i]);
        queue<int> bfs;
        unordered_set<int> visited;
        bfs.push(0);
        while(!bfs.empty()){
            int start=bfs.front();
            bfs.pop();
            if(visited.find(start)==visited.end()){
                visited.insert(start);
                for(int i=start; i<s.size(); i++){
                    string word= s.substr(start, i-start+1);
                    if(dict.find(word)!=dict.end()){
                        bfs.push(i+1);
                        if(i+1==s.size())
                            return true;
                    }
                }
            }
        }
        return false;
    }
};