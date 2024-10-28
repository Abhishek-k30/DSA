class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
         /*
         1 5  2
         1 3  4
         0 1  1
         
         6 8 12  18  
         2 10 14 26
         -2 1  1  8
         
         */
        
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        
         vector<int> oddnums, evenNums, oddTar, evenTar;
         for(int i = 0;i<nums.size();i++){
             if(nums[i]%2)oddnums.push_back(nums[i]);
             else evenNums.push_back(nums[i]);
             
             if(target[i]%2)oddTar.push_back(target[i]);
             else evenTar.push_back(target[i]);
         }
         
        long long minSwaps = 0;
        
        for(int i = 0; i<oddnums.size(); i++){
            minSwaps+= ((oddTar[i]-oddnums[i])>0 ? (oddTar[i]-oddnums[i])/2 : 0);
        }
        for(int i = 0; i<evenNums.size(); i++){
            minSwaps+= ((evenTar[i]-evenNums[i])>0 ? (evenTar[i]-evenNums[i])/2 : 0);
        }
        
        return minSwaps;
    }
};