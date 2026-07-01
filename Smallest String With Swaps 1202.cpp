class DSU {
public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n,1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);

        parent[b]=a;
        sz[a]+=sz[b];
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n=s.size();
        DSU dsu(n);

        for(auto &p:pairs)
            dsu.unite(p[0],p[1]);

        unordered_map<int, vector<int>> groups;

        for(int i=0;i<n;i++)
            groups[dsu.find(i)].push_back(i);

        for(auto &[root, idx]:groups){
            string chars;

            for(int i:idx)
                chars+=s[i];

            sort(chars.begin(),chars.end());
            sort(idx.begin(),idx.end());

            for(int i=0;i<idx.size();i++)
                s[idx[i]]=chars[i];
        }
        return s;
    }
};
