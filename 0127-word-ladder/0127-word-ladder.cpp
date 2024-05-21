class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n= wordList.size();
        
        //bfs
        queue<pair<string, int>> q;   //{word, step}
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        st.erase(beginWord);
        
        while(!q.empty()){
            string s = q.front().first;
            int step = q.front().second;
            q.pop();
            
            if(s==endWord)return step;
            
            for(int i=0; i<s.size(); i++){
                char cur = s[i];
                for(char ch = 'a'; ch<='z' ; ch++){
                    s[i] = ch;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s, step+1});
                    }
                }
                
                s[i] = cur;
            }
        }
        
        return 0;
    }
};

//TC= O(wordlength* 26 * n * logn)
//sc= O(n)