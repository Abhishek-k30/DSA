class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int l = 0 , r = min(n, m);
        int ans = 0;
        while(l<= r){
            int mid = l + (r-l)/2;
            
            multiset<int> st(workers.begin(), workers.end());
            
            int countOfPills = 0;
            bool f = true;
            
            for(int i = mid-1; i>=0; i--){
                auto it = prev(st.end());
                int last = *it;
                
                if(last>= tasks[i]){
                    st.erase(it);
                }
                else{
                    auto it = st.lower_bound(tasks[i] - strength);
                    if(it!=st.end()){
                        countOfPills++;
                        st.erase(it);
                    }
                    else{
                        f = false;
                        break;
                    }
                }
                
                if(countOfPills > pills){
                    f  = false;
                    break;
                }
            }
            
            if(f ){
                ans = max(ans,mid);
                l = mid+1;
            }
            else r = mid-1;
        }
        
        return ans;
    }
};