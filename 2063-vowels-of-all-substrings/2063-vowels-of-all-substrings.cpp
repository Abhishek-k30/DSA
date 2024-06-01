#define ll long long
class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'|| ch=='e' || ch== 'i' || ch=='o' || ch=='u');
    }
    long long countVowels(string word) {
        ll n = word.size();
        ll ans = 0;
        for(ll i=0; i<n; i++){
            if(isVowel(word[i])){
                ans+= (i+1)*(n-i);
            }
        }
        
        return ans;
        
    }
};