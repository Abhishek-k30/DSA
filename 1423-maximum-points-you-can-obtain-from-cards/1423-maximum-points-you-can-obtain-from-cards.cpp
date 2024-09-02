class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(k), suffix(k);
        prefix[0] = cardPoints[0];
        suffix[0] = cardPoints[n-1];
        for(int i = 1; i<k; i++){
            prefix[i] = prefix[i-1] + cardPoints[i];
            suffix[i] = suffix[i-1] + cardPoints[n-i-1];
        }
        int maxSum = 0;
        for(int front = 0; front<=k; front++){
            int end = k-front;
            int frontSum = (front!=0? prefix[front-1] :0);
            int backSum = (end!=0? suffix[end-1] :0);
            
            int sum = frontSum+backSum;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};