class Solution {
public:
    void dfs(int start, int k, int n, vector<int>&ans, vector<vector<int>>& res){
        if(n==0 && k==0){
            res.push_back(ans);
            return;
        }   
        if(n-1<0 || start==10) return;

        for(int i=start; i<=9; i++){
            ans.push_back(i);
            dfs(i+1,k-1,n-i,ans,res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> res;
        dfs(1,k,n,ans,res);
        return res;
    }
};
