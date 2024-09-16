class Solution {
private:
    int convertIntoMins(string cur){
        int totalMins = 0;
        string hrs = cur.substr(0,2);
        string mins = cur.substr(3);
        
        int hr = stoi(hrs);
        int min = stoi(mins);
        
        totalMins = hr*60 + min;
        
        return totalMins;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> minutes;
        
        for(auto &it: timePoints){
            minutes.push_back(convertIntoMins(it));
        }
        
        sort(minutes.begin(), minutes.end());
        
        int mini = INT_MAX;
        
        for(int i = 0; i<minutes.size()-1; i++){
            mini = min(mini, minutes[i+1] - minutes[i]);
        }
        
        mini = min(mini, 24*60-minutes.back()+minutes.front());
        
        return mini;
        
        
    }
};