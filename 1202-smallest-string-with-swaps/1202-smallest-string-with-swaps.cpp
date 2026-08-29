class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a!=b) 
            parent[b] = a; 
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(auto p : pairs){
            unite(p[0], p[1]);
        }

        vector<vector<char>> gp(n);
        for(int i=0; i<n; i++){
            gp[find(i)].push_back(s[i]);
        }

        for(int i=0; i<n; i++){
            sort(gp[i].begin(), gp[i].end());
        }
        vector<int> pos(n,0);
        for(int i=0; i<n; i++){
            int root = find(i);

            s[i] = gp[root][pos[root]];
            pos[root]++;
        }
        return s;
    }
};