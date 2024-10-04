class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long sum = 0;
        int sz = n/2;
        for(int i = 0; i<n; i++){
            sum+=1LL*skill[i];
        }
        if(sum%sz == 1)return -1;
        
        long long ans = 0;
        int l = 0, r = n-1;
        long long tar = sum/sz;
        while(l<r){
            
            long long val = (1LL*skill[l])*(1LL*skill[r]);
            if(tar!=(skill[l]+skill[r])){
                return -1;
            }
            
            ans+=val;
            l++;
            r--;
        }
        
        return ans;
    }
};