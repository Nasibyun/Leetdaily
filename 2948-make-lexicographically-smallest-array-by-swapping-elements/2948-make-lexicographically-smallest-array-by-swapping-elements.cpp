class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> v;

        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        int start=0;
        for(int i=0; i<v.size(); i++){
            int a0 = v[i].first;
            int b0 = v[i+1].first;

            if(i == v.size()-1 || abs(a0-b0) > limit){
                vector<int> idx;

                for(int j=start; j<=i; j++){
                    idx.push_back(v[j].second);
                }

                sort(idx.begin(), idx.end());
                for(int j=0; j<idx.size(); j++){
                    nums[idx[j]] = v[start+j].first;
                }
                start = i+1;
            }
        }
        return nums;
    }
};