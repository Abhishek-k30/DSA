class Solution {
public:
    void mergesort(vector<int>& nums,int l,int r)
    {
        int m=(l+r)/2;
        if(l<r)
        {
            mergesort(nums,l,m);
            mergesort(nums,m+1,r);
            merge(nums,l,m,r);
        }
        else
        {
            return;
        }
    }
    void merge(vector<int>& nums,int l,int m,int r)
    {
        if(l>=r)return;
        int i=l;
        int j=m+1;
        int k=0;
        int size=r-l+1;
        vector<int> v(size,0);
        while(i<=m && j<=r)
        {
            if(nums[i]<nums[j])
            {
                v[k]=nums[i];
                i++;
            }
            else
            {
                v[k]=nums[j];
                j++;
            }
            k++;
        }
        if(i>m)
        {
            while(j<=r)
            {
                v[k]=nums[j];
                k++;
                j++;
            }
        }
        else if(j>r)
        {
            while(i<=m)
            {
                v[k]=nums[i];
                k++;
                i++;
            }
        }
      

        for(int a=0;a<size;a++)
        {
            nums[a+l]=v[a];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};