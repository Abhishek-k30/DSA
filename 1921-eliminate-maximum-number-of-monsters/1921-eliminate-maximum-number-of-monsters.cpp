class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> timeReq;
        for(int i=0;i<dist.size(); i++){
            double time= (double)dist[i]/(double)speed[i];
            timeReq.push_back(time);
        }
        
        sort(timeReq.begin(), timeReq.end());
        
        for(int i=0;i<dist.size(); i++){
            if(timeReq[i]<=i)return i;
        }
        return dist.size();
    }
};