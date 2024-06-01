class Solution {
   
public:
    long mod = 100000000000007L;
    long power =1L;
    
    long initHash(string  &s, int start, int end ){
        long hash = 0;
        for(int i=0; i<end; i++){
            hash = (hash*26L)+(s[i+start]-'a'+1);
            hash %=mod;
        }
        return hash;
    }
      
    long rehash(string &s, int cur, int end, long &hash){
        long sub = s[cur-1] -'a'+1;
        long add = s[cur+end-1] - 'a' + 1;
        hash= ((hash*26L)%mod + add)%mod;
        hash = hash-(sub*power)%mod;
        hash = (hash+mod)%mod;
        
        return hash;
    }
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        int len = 1;
        unordered_set<long> st;
        
        while(len<=n/2){
            int left =0, right = len;
            long leftHash = initHash(text, left, len);
            long rightHash = initHash(text, right, len );
            
            power= (power*26)%mod;
            
            if(leftHash == rightHash && st.find(leftHash)==st.end())st.insert(leftHash);
            left++;
            right++;
            
            while(right<=n-len){
                leftHash = rehash(text, left, len, leftHash);
                rightHash = rehash(text, right, len, rightHash);
                if (leftHash == rightHash && st.find(leftHash) == st.end()) st.insert(leftHash);
                left++;
                right++;
            }
            
            len++;
        }
        
        return st.size();
    }
};