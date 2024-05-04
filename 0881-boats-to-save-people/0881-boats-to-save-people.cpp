class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int l=0, r=n-1;
        int cnt=0;
        sort(people.begin(), people.end());
        while(l<=r){
            if(people[l]+people[r]<=limit){
                cnt++;
                l++;
                r--;
            }
            else{
                r--;
                cnt++;
            }
        }
        
        return cnt;
    }
};