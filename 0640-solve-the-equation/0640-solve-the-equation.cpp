class Solution {
public:
    string solveEquation(string equation) {
        string ans="x=";
        int n=equation.size();
        int leftXcount=0, rightXcount=0;
        int leftSum=0, rightSum=0;
        int ind=0;
        int mul1=1, mul2=0;
        int ins=1;
        int in=0;
        
        // Left Side
        for(int i=0; i<n; i++){
            if(equation[i]=='='){
                ind=i;
                break;
            }
            if(i==0){
                if(equation[i]=='-')mul1=-1;
                else if(equation[i]=='x')leftXcount++;
                else if(equation[i]!='+'){mul2=(equation[i]-'0');
                                         if(mul2==0)ins=0;}
                
            }
            else{
                if(equation[i]=='x'){  
                    if(ins==0) {leftXcount+=0;
                               ins=1;}
                    
                    else{
                    if(mul2!=0)leftXcount+=mul2*mul1;
                    else leftXcount+=mul1;
                    }
                    
                    mul1=1;
                    mul2=0;
                    in=0;
                }
                else if(equation[i]=='+'){
                     leftSum+=(mul1*mul2);
                     mul2=0;
                     mul1=1;
                    in=0;
                }
                else if(equation[i]=='-'){
                     leftSum+=(mul1*mul2);
                     mul2=0;
                     mul1=-1;
                    in=0;
                }
                else { mul2=mul2 *10+(equation[i]-'0');
                      if(mul2==0)ins=0;
                     }
            }
        }
        leftSum+=(mul1*mul2);
        
        //Right Side
        in=0;
        ins=1;
         mul1=1, mul2=0;
        for(int i=ind+1; i<n; i++){
            if(equation[i]=='='){
                ind=i;
                break;
            }
            if(i==ind+1){
                if(equation[i]=='-')mul1=-1;
                else if(equation[i]=='x')rightXcount++;
                else if(equation[i]!='+'){mul2=(equation[i]-'0');
                                           if(mul2==0)ins=0;}
            }
            else{
                if(equation[i]=='x'){   
                   if(ins==0) {rightXcount+=0;
                    ins=1;
                              }
                    
                    else{
                    if(mul2!=0)rightXcount+=mul2*mul1;
                    else rightXcount+=mul1;
                    }
                    
                    mul1=1;
                    mul2=0;
                    in=0;
                }
                else if(equation[i]=='+'){
                   rightSum+=(mul1*mul2);
                     mul2=0;
                     mul1=1;
                    in=0;
                }
                else if(equation[i]=='-'){
                   rightSum+=(mul1*mul2);
                     mul2=0;
                     mul1=-1;
                    in=0;
                }
                else { mul2=mul2 *10+(equation[i]-'0');
                      if(mul2==0)ins=0;
                     }
            }
        }
        rightSum+=(mul1*mul2);
        int xval=leftXcount-rightXcount;
        int num=rightSum-leftSum;
        cout<<leftXcount<<" "<<rightXcount<<endl;
        if(leftXcount==rightXcount && num!=0)return "No solution";
        if(xval==0)return "Infinite solutions";
        else ans+=to_string(num/xval);
         //cout<<num<<endl;;
        return ans;
    }
};