class Solution {
public:
    bool good(vector<int> &hash){
        return ( hash[0]>0 && hash[1]>0 && hash[2]>0);
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int idx = 0, ans = 0;
        vector<int> hash(26, 0);
        while(idx<n && !good(hash)){
            hash[s[idx]-'a']++;
            idx++;
        }
        if(idx>=n && !good(hash))return 0;
        ans+= 1+n-idx;
        //cout<<idx<<endl;
        for(int i=1; i<n; i++){
            hash[s[i-1]-'a']--;
            while(idx<n && !good(hash)){   
            hash[s[idx]-'a']++;
            idx++;
            }
            if(good(hash)){
                ans+=(1+ n-idx);
            }
            //idx++;
        }
        return ans;
    }
};