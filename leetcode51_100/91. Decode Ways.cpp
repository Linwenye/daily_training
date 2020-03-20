
class Solution {
public:
    int numDecodings(string s) {
        if(!s.size()) return 0;
        
        int *res = new int[s.size()+1]();
        if(s[s.size()-1]=='0'){
            res[s.size()-1]=0;
        }
        else{
            res[s.size()-1] = 1;
        }
        res[s.size()]=1;
        for(int i=int(s.size())-2;i>=0;i--){
            if(s[i]=='0'){
                res[i]=0;
            }
            else{
                int combine = (s[i]-'0')*10+s[i+1]-'0';
                if(combine<=26){
                    res[i]=res[i+1]+res[i+2];
                }
                else{
                    res[i]=res[i+1];
                }
            }
        }
        return res[0];
        
    }
};