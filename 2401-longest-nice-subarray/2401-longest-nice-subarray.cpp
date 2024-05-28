class fun{
  
    public:
     
   vector<vector<int>> v;
    map<int, int> m;

    fun() : v(32, vector<int>(100005, 0)) {}
    void add(int num , int idx){
        for(int i=0; i<=31; i++){
            if(num & (1<<i)){
                v[i][idx] = 1;
                m[i]++;
            }
        }
    }
    void remove(int num, int idx){
        for(int i=0; i<=31; i++){
             if(v[i][idx]==1)m[i] = max(m[i]-1, 0);
             v[i][idx] = 0;
        }
    }
    
    bool good(){
        for(auto &it: m)if(it.second>1)return false;
        return true;
        
    }
};
class Solution {
public:
    
     
    
    int longestNiceSubarray(vector<int>& nums) {
        
        fun f;
        int n = nums.size();
        int l = 0 , ans = 0;
        
        for(int r = 0; r<n; r++){
            f.add(nums[r], r);
            while(l<=r && !f.good()){
                f.remove(nums[l], l);
                l++;
            }
            
            if(f.good())ans= max(ans, r-l+1);
            
            //cout<<r+1<<" "<<l+1<<" "<<ans<<endl;
        }
        
        //cout<<endl;
        return ans;
    }
};
//000011
//001000
//110000
//001010