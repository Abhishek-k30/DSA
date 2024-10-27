class Solution {
private:
    long long gcd(long long a, long long b){
        if(b==0)return a;
        return gcd(b, a%b);
    }
    long long lcm(long long a, long long b){
        return (a*b)/(gcd(a,b));
    }
public:
    long long maxScore(vector<int>& nums) {
        long long curGCD = nums[0], curLCM = nums[0];
        
        for(int i = 1; i<nums.size(); i++){
            curGCD = gcd(curGCD, nums[i]);
            curLCM = lcm(curLCM, nums[i]);
        }
        
        long long maxi = curGCD*curLCM;
        
        for(int i = 0; i<nums.size(); i++){
            long long g=0, l = 1;
            for(int j = 0; j<nums.size(); j++){
                if(i==j)continue;
                else {
                    g = gcd(g, nums[j]);
                    l = lcm(l, nums[j]);
                }
            }
           // cout<<g<<" "<<l<<endl;
            maxi = max(maxi, l*g);
        }
        
        return maxi;
    }
};