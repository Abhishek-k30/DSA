class Solution {
private:
    long divisorSum(long num){
        long cnt = 0, sum = 0;
        for(long i = 1; i<=sqrt(num); i++){
            if(num%i==0){
                if(num/i==i){
                    cnt++;
                    sum+=i;
                }
                else{
                    cnt+=2;
                    sum+=i;
                    sum+=(num/i);
                }
            }
        }
        if(cnt==4)return sum;
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        long sumOfDivisors = 0;
        for(auto &it: nums){
            sumOfDivisors+=divisorSum(it);
        }
        
        return sumOfDivisors;
    }
};