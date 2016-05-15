#include "common.h"

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int nA = max(A, E);
        int nB = max(B, F);
        int nC = min(C, G);
        int nD = min(D, H);
        int overlap = 0;
        if ((nA<nC)&&(nB<nD))
            overlap = (nC-nA)*(nD-nB);
        return (C-A)*(D-B)+(H-F)*(G-E)-overlap;
    }
};
 
int main() {
    Solution s;
    s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    return 0;
}
