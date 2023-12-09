class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        int longest=0;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        
        for(int i=0; i<n ; i++){
            if(s.find(nums[i]-1)==s.end()){
                int cnt=0;
                int curr=nums[i];
                
                while(s.find(curr)!=s.end()){
                    cnt++;
                    curr++;
                }
                
                longest=max(longest, cnt);
            }
        }
        
        
        return longest;
    }
};

//TC= O(3n)==O(n), SC=O(n)