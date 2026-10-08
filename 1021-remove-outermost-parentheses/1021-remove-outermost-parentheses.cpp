class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int open = 0;
        for(int i = 0 ;i<s.length();i++){
            if(s[i]=='('){
                if(open>0){
                    result += "(";
                   
                }
                 open++; 
            }
            else{
                open--;
                if(open>0){
                    result += ")";
                }
            }
        }
        return result;
        
    }
};