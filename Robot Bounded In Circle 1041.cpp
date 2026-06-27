class Solution {
public:
    bool isRobotBounded(string instructions) {
        // North, East, South, West
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int x = 0, y = 0;
        int d = 0; // 0=N, 1=E, 2=S, 3=W

        for(char c : instructions){
            if (c == 'G') {
                x += dir[d].first;
                y += dir[d].second;
            } 
            else if(c == 'L'){
                d = (d + 3) % 4;
            } 
            else{
                d = (d + 1) % 4;
            }
        }

        return (x == 0 && y == 0) || d != 0;
    }
};
