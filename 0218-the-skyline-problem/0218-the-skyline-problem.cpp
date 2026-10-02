class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> events;
        for(auto it:buildings){
            events.push_back({it[0],it[2]});
            events.push_back({it[1],-it[2]});
        }
        sort(events.begin(),events.end());

        int curmax , prevmax = 0;
        multiset<int> active = {0};
        int i = 0;
        int n = events.size();
        vector<vector<int>> res;
        while(i<n){
            int x = events[i][0];
            while(i< n && x == events[i][0]){
                int h = events[i][1];
                if(h>0) active.insert(h);
                else active.erase(active.find(-h));
                i++;
            }
            curmax = *active.rbegin();
            if(curmax != prevmax){
                res.push_back({x,curmax});
                prevmax = curmax;
            }
        }
        return res;
    }
};