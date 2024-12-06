class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        banned.erase(unique(banned.begin(), banned.end()), banned.end());
        
        int cnt = 0, pos = 0, sum = 0;
        
        for(int i = 1; i<=n; i++){
            if(pos<banned.size() && banned[pos] ==i){
                pos++;
                continue;
            }
            if(sum + i <= maxSum){
                cnt++;
                sum+=i;
            }
            else break;
        }
        
        return cnt;
    }
};