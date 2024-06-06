class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int  n =  hand.size();
        if(n%groupSize!=0)
            return false;
        
        multiset<int> st;
        for(auto &it: hand)
            st.insert(it);
        
         // 1 2  2 3 3 4 6 7 8
        
        int sz = n/groupSize;
        for(int i=0; i<sz; i++){
            int cur = *st.begin();
            st.erase(st.find(cur));
            for(int j=0; j<groupSize-1; j++){
                if(st.find(cur+j+1)!=st.end()){
                    st.erase(st.find(cur+j+1));
                }
                else return false;
            }
        }
        
        return true;
    }
};