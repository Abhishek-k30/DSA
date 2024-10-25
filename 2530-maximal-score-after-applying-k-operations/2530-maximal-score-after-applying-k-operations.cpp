class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0 ; i< nums.size() ; i++){
            pq.push(nums[i]);
        }
        long long score=0;
        for(int i=0 ; i<k ; i++){
            int node=pq.top();
            pq.pop();
            score+=node;
            int a=(node)/3;
            if(node%3!=0)a++;
            pq.push(a);
        }
        
        return score;
    }
};