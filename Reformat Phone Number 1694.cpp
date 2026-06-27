class Solution {
public:
    string reformatNumber(string number) {
        string x = "";
        for(char c : number){
            if(isdigit(c)){
                x.push_back(c);
            }
        }
        string res;
        int i = 0;
        int n = x.size();

        while(n-i > 4){
            res += x.substr(i, 3);
            res.push_back('-');
            i += 3;
        }

        if(n-i == 4){
            res += x.substr(i, 2);
            res.push_back('-');
            res += x.substr(i+2, 2);
        }
        else{
            res += x.substr(i);
        }
        return res;
    }
};
