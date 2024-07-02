class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //1st approch
        // hashing tc = O(nlogn) , sc = O(n)
        
        //sorting + two pointer Tc = O(nlogn), sc = o(1)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        int l = 0;
        for(int i = 0; i<n1; i++){
            int cur = nums1[i];
            while(l<n2 && cur > nums2[l]){
                l++;
            }
            
            if(l<n2 && cur == nums2[l]){
                ans.push_back(cur);
                l++;
            }
        }
        
        return ans;
    }
};