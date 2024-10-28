class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
          
        // check 1 - freq of all int should be even else return -1
        // 1 1 2 4
        // 2 2 2 4
        
        int n = basket1.size();
        
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());
        
        map<int, int> totalFreq, freq1, freq2;
        
        for(int i = 0 ; i<n; i++){
            totalFreq[basket1[i]]++;
            totalFreq[basket2[i]]++;
            
            freq1[basket1[i]]++;
            freq2[basket2[i]]++;
        }
        
        for(auto &it: totalFreq){
            if(it.second%2)return -1;
        }
        
        long long minSwaps = 0;
        
//         for(int i = 0; i<n; i++){
//             if(basket1[i] == basket2[i]){
//                 continue;
//             }
//             else{
//                 int totCnt1 = mpp[basket1[i]];
//                 int totCnt2 = mpp[basket2[i]];
                
                
//             }
//         }
        
        long long mn = totalFreq.begin()->first;
        
        vector<int> temp1, temp2;
        for(auto &it : freq1){
            int cnt = it.second;
            int netCnt = totalFreq[it.first];
            
            for(int i = 0; i< (cnt-(netCnt/2)); i++){
                temp1.push_back(it.first);
            }
        }
        for(auto &it : freq2){
            int cnt = it.second;
            int netCnt = totalFreq[it.first];
            
            for(int i = 0; i< (cnt-(netCnt/2)); i++){
                temp2.push_back(it.first);
            }
        }
        
        if(temp1.size()!=temp2.size()){
            return -1;
        }
        else{
            
            reverse(temp2.begin(), temp2.end());
            
            for(int i = 0; i<temp1.size(); i++){
                minSwaps+= min(2*mn,(long long)min(temp1[i], temp2[i]));
            }
        }
        
        return minSwaps;
    }
};