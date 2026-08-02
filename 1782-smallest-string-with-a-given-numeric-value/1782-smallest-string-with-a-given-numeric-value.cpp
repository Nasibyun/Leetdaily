class Solution {
public:
    char tochar(int x){
        return 'a' + (x-1);
    }
    string getSmallestString(int n, int k) {
        string ans="";
        while(k>0){
            if(k-26 >= n-1){
                ans.push_back('z');
                k-=26;
            }else{
                int d = k-(n-1);
                ans.push_back(tochar(d));
                k-=d;
            }
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};