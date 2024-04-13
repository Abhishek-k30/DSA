class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    stack<int> s;
    height.push_back(0);
    int maxSize = 0;
    for(int i = 0; i < height.size(); i++){
        if(s.empty() || height[i] >= height[s.top()]){
            s.push(i);
        }
        else{
            int temp = height[s.top()];
            s.pop();
            maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
            i--;
        }
    }
    return maxSize;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0 || m==0)return 0;
        int maxRec=0;
        vector<int> heights(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0')heights[j]=0;
                else heights[j]++;
            }
            maxRec=max(maxRec, largestRectangleArea(heights));
            
        }
        
        return maxRec;
    }
};