class Solution {
public:
    int mod=1e9+7;
//     int f(string s , int low, int high , string a, string b, unordered_set<string> &st ){
        
//         // Base Case
//          //cout<<st.size()<<endl;
         
//         if(s.size()>high)return 0;
//         if(s.size()>=low && s.size()<=high) st.insert(s);
        
       
        
//         return f(s+a,low,high,a,b, st) + f(s+b,low,high,a,b, st)
//               +f(a+s,low,high,a,b, st)+f(b+s,low,high,a,b,st);
        
         
        
        
        
        
        
        
        
        
//     }
    
    int score(int target, vector<int> &dp, int one, int zero){
        
        // Base Case
        if(target==0)return 1; // string created
        if(target<0)return 0; // string not possible
        
        // Memoization
        if(dp[target]!=-1)return dp[target];
        
        long long sum=0;
        
        // checking both possible ways of either adding one or zero;
        sum=(score(target-one, dp, one, zero)%mod+score(target-zero, dp, one, zero)%mod)%mod;
        
        // Returning total sum
        return dp[target]=sum%mod;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
//         string a="", b="";
//         for(int i=0;i<zero; i++)a+='0';
//         for(int i=0;i<one; i++)b+='1';
        
//         string temp="";
//         unordered_set<string> st;
//          int ans= f(temp,low,high,a,b, st);
//         return st.size()%mod;
        vector<int> dp(high+1,-1);
        int ans=0;
        for(int i=low; i<=high; i++){
            ans=((ans%mod)+(score(i,dp,one, zero)%mod))%mod;
        }
        
        return ans;
    }
};