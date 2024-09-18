class Solution {
public:
    static bool comp(string& a, string& b)
{
    return a+b>b+a;
}
    string largestNumber(vector<int>& nums) {
        vector<string> t;
        for(int i=0; i< nums.size(); i++){
            string a=to_string(nums[i]);
            t.push_back(a);
            
        }
        sort(t.begin(), t.end(), comp);
         
        string ans="";
        for(int i=0; i< t.size(); i++){
            ans+=t[i];
        }
        int j=0;
        while(j<ans.size()-1 && ans[j]=='0'){
            j++;
        }
        return ans.substr(j, ans.size());

    }
};