class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
          int n = nums.size();
        vector<vector<int>> v(n, vector<int>(32,0));
        
        for(int i = 0; i<n; i++){
            int cur = nums[i];
            for(int j=0; j<=31; j++){
                if(cur & (1<<j))v[i][j] = 1;
            }
             
        }
        
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<32; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // cout<<endl;
        
        int ans = 0;
        for(int i=0; i<32; i++){
            unordered_map<int, int> m;
            for(int j=0; j<n; j++){
                m[v[j][i]]++;
            }
            
            int cnt = n;
            
            for(int j=0; j<n; j++){
                int cur = cnt - m[v[j][i]];
                cnt--;
                
                m[v[j][i]]--;
                if(m[v[j][i]]<0)
                    m.erase(v[j][i]);
                
                ans+=cur;
                
                
            }
        }
         
        
        return ans;
    }
};