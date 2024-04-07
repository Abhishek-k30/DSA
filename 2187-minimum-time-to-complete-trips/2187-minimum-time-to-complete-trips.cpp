#define ll long long
class Solution {
public:
    bool good(vector<int>& time, int k, ll m){
        ll sm=0;
        for(int i=0; i<time.size(); i++){
            sm+=(m/((ll)time[i]));
        }
        return sm>=k;
    }
    long long minimumTime(vector<int>& time, int k) {
        int n=time.size();
        ll l=1, r=1e14;
        for(int i=0; i<100; i++){
            ll m= l+ (r-l)/2;
            if(good(time, k, m))r=m;
            else l=m;
        }
        
        return r;
        
    }
};