class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq; 
        for(int i = 0; i< n; i++){
            pq.push({courses[i][1], courses[i][0]});
        }
        
        int cnt=0;
        int curTime=0;
        priority_queue<int> q;
        while(!pq.empty()){
            int endTime = pq.top().first;
            int timeTaken = pq.top().second;
            pq.pop();
            
            curTime+=timeTaken;
            q.push(timeTaken);
            
            if(curTime>endTime){
                // cout<<q.top()<<" ";
                curTime-= q.top();
                q.pop();
            }
            
        }
        
        //cout<<endl;
        return q.size();
    }
};
//TC = O(Ologn)
//SC = O(n)