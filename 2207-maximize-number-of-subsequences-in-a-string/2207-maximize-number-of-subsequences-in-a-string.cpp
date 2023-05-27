class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char a=pattern[0];
        char b=pattern[1];
        
        int n=text.size();
        string t1=a+text;
        string t2=text+b;
        
        
        
        vector<long long> pt1(n+1,0);
        vector<long long> pt2(n+1,0);
        
        pt2[n]=1;
        pt1[n]=(t1[n]==b);
        
        
        for(int i=n-1; i>=0; i--){
            if(t1[i]==b){
                pt1[i]=1+pt1[i+1];
               
            }
            else pt1[i]=pt1[i+1];
            
            
        }
        
         for(int i=n-1; i>=0; i--){
            if(t2[i]==b){
                pt2[i]=1+pt2[i+1];
            }
            else pt2[i]=pt2[i+1];
        }
        
        long long ans1=0;
        long long ans2=0;
        
        if(a==b){
             for(int i=0; i<n+1; i++){
            
            
            if(t1[i]==a){
                
                ans1+= max(pt1[i]-1, (long long)0);
            }
            if(t2[i]==a){
                ans2+=max(pt2[i]-1, (long long)0);
            }
        }
        } 
        else{
        for(int i=0; i<n+1; i++){
            
            
            if(t1[i]==a){
                ans1+=pt1[i];
            }
            if(t2[i]==a){
                ans2+=pt2[i];
            }
        }
        }
        
        return max(ans1, ans2);
            
    }
};