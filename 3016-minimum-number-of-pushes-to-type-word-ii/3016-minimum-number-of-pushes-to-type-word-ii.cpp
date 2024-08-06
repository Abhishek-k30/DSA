class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char , int> mpp;
        for(auto &it : word){
            mpp[it]++;
        }
        
        long long pressed = 0;
        vector<int> freq;
        for(auto &it : mpp){
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int cnt = 1;
        int idx = 0;
        for(int i = 0; i<freq.size(); i++){
             if(idx%8==0 && idx!=0)
                 cnt++;
            
            pressed+= 1LL*(cnt)*(freq[i]);
            idx++;
        }
        return pressed;
    }
};