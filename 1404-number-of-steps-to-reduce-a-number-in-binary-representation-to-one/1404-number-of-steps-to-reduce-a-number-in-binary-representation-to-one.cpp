class Solution {
public:
    void add(string &s){
        int carry= 0;
        for(int i=s.size()-1; i>=0; i--){
            int bit1 = s[i]- '0';
            int bit2 =  (i==s.size()-1 ? 1 : 0);
            
            int addedValue = bit1^bit2^carry;
            carry = (bit1&bit2) + (bit1&carry) +  (bit2&carry);
            
            s[i] = (addedValue) + '0';
            
        }
        if(carry==1){
        reverse(s.begin(), s.end());
        s+='1';
        reverse(s.begin(), s.end());
        }
    }
    
    void divide(string &s){
        
        s.pop_back();
        reverse(s.begin(), s.end());
        s+='0';
        reverse(s.begin(), s.end());
        
    }
    
    bool good(string &s){
        bool f1=(s.back()=='1'? true : false);
        int cnt =0;
        for(int i=s.size()-2; i>=0; i--){
            if(s[i]=='1')cnt++;
        }
        
        if(cnt==0 && f1)return true;
        return false;
    }
    int numSteps(string s) {
         int n = s.size();
         
        
        int ops = 0;
        while(  !good(s)){
            if(s.back() == '1'){
                add(s);
                ops++;
            }
            else{
                divide(s);
                ops++;
            }
            
            //cout<<s<<" "<<good(s)<<endl;
        }
        
        //cout<<endl;
        return ops;
    }
};