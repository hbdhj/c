class Solution {
public:
    int reverse(int x) {
    int nx = x;
    if (x<0)
        nx=-x;
    int ret = 0;
    while(nx>0)
    {
        if ((ret*10)>(0xFFFFFFFF-(nx%10)))
        {
            ret = 0;
            break;
        }
        ret=ret*10+nx%10;
        nx=nx/10;
    }
    if (x<0)
        return 0-ret;
    return ret;
    }
};
