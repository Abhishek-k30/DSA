class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> m; 
        for(int i=0;i<names.size();i++)
        {
            if(m.find(names[i])!=m.end()) 
            {
                int k=m[names[i]]; 
                while(m.find(names[i]+"("+to_string(k)+")")!=m.end())
                {
                    k++; 
                    m[names[i]]++; 
                }
                m[names[i]]++; 
                 names[i]=names[i]+"("+to_string(k)+")";
            }
            m[names[i]]=1; 
        }
        return names;
    }
};