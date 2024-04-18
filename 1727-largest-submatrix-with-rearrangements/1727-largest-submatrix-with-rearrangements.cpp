class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int> height(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0)height[j]=0;
                else height[j]++;
            }
        
        vector<int> ones=height;
        sort(ones.begin(), ones.end());
        for(int j=0; j<m; j++){
            ans=max(ans, ones[j]*(m-j));
        }
        }
        return ans;
    }
};

// used the concept of largest area in histogram