class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
         
        map<int, int> mpp;
        
        for(auto &it : basket1)mpp[it]++;
        for(auto &it: basket2)mpp[it]--;
        
        
        vector<int> swapB1toB2, swapB2toB1;
        
        for(auto &it : mpp){
            if(it.second%2)return -1;
            
            if(it.second>0){    // swap from b1 to b2
                
                int cnt = it.second/2;
                while(cnt--)swapB1toB2.push_back(it.first);
            }
            else{       // swap from b2 to b1
            
                int cnt = -it.second/2;
                while(cnt--)swapB2toB1.push_back(it.first);
            }
        }
        
        reverse(swapB2toB1.begin(), swapB2toB1.end());
        
        long long minCost = 0;
        
        long long mn = mpp.begin()->first;
        
        for(int i = 0; i<swapB1toB2.size(); i++){
            minCost+= min(2*mn, (long long)min(swapB1toB2[i], swapB2toB1[i]));
        }
        
        return minCost;
    }
};