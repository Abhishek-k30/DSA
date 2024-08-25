class Solution {
private:
    bool check(int l, int r){
         string s1 = to_string(l);
         string s2 = to_string(r);
        
         if(s1.size()<s2.size()){
             while(s1.size()<s2.size())s1= '0'+s1;
         }
        else if(s1.size()>s2.size()){
            while(s2.size()<s1.size())s2='0'+s2;
        }
        
        unordered_map<char, int> mpp1, mpp2;
        int diff = 0;
        for(int i = 0; i<s1.size(); i++){
            if(s1[i]!=s2[i])diff++;
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }
        
        return diff<=2 && mpp1==mpp2;
        
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0;  i<n; i++){
            for(int j = i+1; j<n; j++){
                if(check(nums[i], nums[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};