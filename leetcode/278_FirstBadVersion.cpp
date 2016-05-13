// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        int mid = -1;
        while(i<j) {
            mid = (j-i)/2+i; // this is a tricky line, mid = (i+j)/2 will not work
            if (isBadVersion(mid)) {
                j=mid;
            } else {
                i = mid+1;
            }
        }
        return i;
    }
};
