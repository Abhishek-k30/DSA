class Solution {
private:
    bool check(int l, int r){
        vector<int> digitl, digitr;
        while(l>0){
            digitl.push_back(l%10);
            l/=10;
        }
         while(r>0){
            digitr.push_back(r%10);
            r/=10;
        }
        
        reverse(digitl.begin(), digitl.end());
        reverse(digitr.begin(), digitr.end());
        int s1= digitl.size(), s2 = digitr.size();
        if(s1<s2){
            reverse(digitl.begin(), digitl.end());
            int cur=s1;
            while(digitl.size()<s2){
                digitl.push_back(0);
            }
            reverse(digitl.begin(), digitl.end());
        }
        else if(s2<s1){
            reverse(digitr.begin(), digitr.end());
            int cur=s1;
            while(digitr.size()<s1){
                digitr.push_back(0);
            }
            reverse(digitr.begin(), digitr.end());
        }
        
        if(digitl==digitr)return true;
        vector<int> base1 = digitl, base2 = digitr;
        for(int i = 0; i<digitl.size(); i++){
            for(int j = i+1; j<digitl.size();j++ ){
                swap(digitl[i], digitl[j]);
                if(digitl== base2)
                    return true;
                
                digitl = base1;
            }
        }
        
        for(int i = 0; i<digitr.size(); i++){
            for(int j = i+1; j<digitr.size();j++ ){
                swap(digitr[i], digitr[j]);
                if(digitr== base1)
                    return true;
                
                digitr = base2;
            }
        }
        
        return false;
        
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