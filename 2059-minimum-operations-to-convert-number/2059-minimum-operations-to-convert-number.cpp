class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        int steps = 0;
        vector<int> visited(1001, 0);
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int cur = q.front();
                q.pop();
                
                if(cur == goal)
                    return steps;
                if(cur>1000 || cur<0 || visited[cur] )
                    continue;
                visited[cur] = 1;
                
                for(int i=0; i<n; i++){
                    q.push(cur + nums[i]);
                    q.push(cur - nums[i]);
                    q.push(cur ^ nums[i]);
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};