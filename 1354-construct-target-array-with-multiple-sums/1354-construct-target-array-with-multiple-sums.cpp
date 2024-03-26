class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        priority_queue<int> pq;
        long long int sum=0;
        for(int i=0; i<n; i++){
            pq.push(target[i]);
            sum+=target[i];
        }
        
        while(!pq.empty()){
            if(pq.top()==1)break;
            sum-=pq.top();
            if(sum==0 || sum>=pq.top())return false;
            
            int rem= pq.top()%sum;
            if(sum!=1 && rem==0)return false;
            
            pq.pop();
            pq.push(rem);
            sum+=rem;
        }
        
         
        return true;
    }
};