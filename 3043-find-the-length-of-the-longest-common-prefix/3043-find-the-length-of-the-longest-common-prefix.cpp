class Solution {
public:
    int check(int a, int b){
        string s=to_string(a), t=to_string(b);
         int f=0;
        for(int i=0; i<min(s.size(), t.size()); i++){
            if(s[i]==t[i])f++;
            else break;
        }
        return f;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         
        int cnt=0;
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        unordered_map<string, int> pre;

        for (int num : arr1) {
            string str = to_string(num);
            for (int i = 1; i <= str.length(); ++i) {
                pre[str.substr(0, i)]++;
            }
        }

        int maxLen = 0;
        for (int num : arr2) {
            string str = to_string(num);
            for (int i = 1; i <= str.length(); ++i) {
                if (pre.count(str.substr(0, i))) {
                    maxLen = max(maxLen, i);
                } else {
                    break;
                }
            }
        }

        return maxLen;
        
                            
        
        
        
    }
};