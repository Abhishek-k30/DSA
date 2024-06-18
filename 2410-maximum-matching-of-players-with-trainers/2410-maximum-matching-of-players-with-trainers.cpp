class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(), players.end());
        multiset<int> st(trainers.begin(), trainers.end());
        int cnt = 0;
        
        for(auto & player : players){
            auto it = st.lower_bound(player);
            if(it!=st.end()){
                cnt++;
                st.erase(it);
            }
        }
        
        return cnt;
    }
};