class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x3=max(x1,min(x2,xc));
        int y3=max(y1,min(y2,yc));
        return (x3-xc)*(x3-xc)+(y3-yc)*(y3-yc)<=r*r;
    }
};