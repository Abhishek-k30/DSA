class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int mxSum = -1;
        int idx = 0;
        int zero =0;
        int sum = 0;
        for(int i = 0; i<minutes; i++){
            if(grumpy[i])
                sum+=customers[i];
        }
        
        mxSum = sum;
        int idx1 = -1;
        for(int i = minutes; i<n; i++){
            if(grumpy[i])
                sum+=customers[i];
            if(grumpy[idx])
                sum-=customers[idx];
            
            if(sum>mxSum){
                idx1 = idx;
                mxSum = sum;
            }
            
            idx++;
        }
        
        int ans = 0;
        idx1++;
        int en = idx1 + minutes;
        
        for(int i = 0; i<min(idx1,n); i++){
            
                   if(!grumpy[i])
               ans+= customers[i];
        }
    
        for(int i = idx1; i<min(en, n); i++)
            ans+=customers[i];
        
        
        for(int i = en; i<n; i++){
            if(!grumpy[i])
                ans+=customers[i];
        }
        
        cout<<mxSum<<" "<<idx1<<endl;
        
        return ans;
    }
};