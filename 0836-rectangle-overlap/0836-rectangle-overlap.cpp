class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        int a1=r1[0], b1=r1[1], c1=r1[2], d1=r1[3];
        int a2=r2[0], b2=r2[1], c2=r2[2], d2=r2[3];

        if((a2-c1)<0 && (b2-d1)<0 && (a1-c2)<0 && (b1-d2)<0){
            return true;
        }
        return false;
    }
};