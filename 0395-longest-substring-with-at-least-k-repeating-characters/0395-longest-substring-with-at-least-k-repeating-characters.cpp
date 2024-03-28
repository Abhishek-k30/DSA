class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(k==1)return n;
        
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++)freq[s[i]]++;
        
        int left=0;
        while(left<n && freq[s[left]]>=k)left++;
        
        if(left>=n-1)return left;
        
        int l1=longestSubstring(s.substr(0, left), k);
        
        while(left<n && freq[s[left]]<k)left++;
        
        int l2=left<n ? longestSubstring(s.substr(left), k ): 0;
        
        return max(l1, l2);
    }
};