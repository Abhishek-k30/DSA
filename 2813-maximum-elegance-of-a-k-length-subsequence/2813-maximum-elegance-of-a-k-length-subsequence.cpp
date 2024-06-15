#define ll long long
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        sort(items.begin(), items.end());
        reverse(items.begin(), items.end());
        
        map<int,  int> cat;
        ll profit = 0;
        int ind = k-1;
        for(int i=0; i<k; i++){
            profit+=items[i][0];
            cat[items[i][1]]++;
            
        }
        
        ll sz = cat.size();
        ll curans = profit + sz*sz;
        for(int i=k; i<n; i++){
            int cur = items[i][1];
            if(cat.find(cur)==cat.end()){
                while(ind>=0){
                     int c = items[ind][1];
                     if(cat[c]==1)
                         ind--;
                    else{
                        ll now = profit-items[ind][0] + items[i][0] + (sz+1)*(sz+1);
                       // if(now>=curans){
                            curans = max(curans, now);
                            profit = profit-items[ind][0] + items[i][0];
                            sz++;
                            cat[items[ind][1]]--;
                            cat[cur]++;
                            ind--;
                             break;
                        // }
                        // else  break;
                    }
                }
            }
        }
        
        return curans;
    }
};