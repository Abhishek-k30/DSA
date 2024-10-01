class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem;
        map<int, int> mpp;
        for(int i = 0; i<arr.size(); i++){
            
            int x = ((arr[i]%k)+k)%k;
            
            mpp[x]++;
        }
        
        for(auto it: mpp){
            if(it.first == 0){
                if(mpp[it.first]%2!=0)return false;
            }
            else {
                if(mpp[it.first]!=mpp[k-it.first])return false;
            }
        }
        
        return true;
    }
};