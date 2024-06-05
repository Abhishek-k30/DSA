class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int  n = asteroids.size();
        priority_queue<int, vector<int>,
        greater<int>> pq;
        for(int i = 0; i<n; i++){
            pq.push(asteroids[i]);
        }
        
         
        long long planetMass =  1LL*mass;
        while(!pq.empty()){
            int mn = pq.top();
            pq.pop();
            
            if(planetMass>=mn){
                planetMass += 1LL*mn;
            }
            else return false;
        }
        
        return true;
    }
};