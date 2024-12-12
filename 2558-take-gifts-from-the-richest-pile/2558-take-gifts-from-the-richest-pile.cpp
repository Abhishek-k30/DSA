class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        long long sum = 0;
        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            sum+=1LL*gifts[i];
            pq.push(gifts[i]);
        }
        
        while(k-- && !pq.empty()){
            int top = pq.top();
            pq.pop();
            int rem = sqrt(top);
            sum-= (top - rem);
            pq.push(rem);
        }
        
        return sum;
        
        
    }
};