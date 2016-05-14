class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int point_to_insert=m+n-1;
        int point_to_end_nums1 = m-1;
        int point_to_end_nums2 = n-1;

        while(point_to_insert>=0&&point_to_end_nums1>=0&&point_to_end_nums2>=0) {
            if (nums1[point_to_end_nums1]<nums2[point_to_end_nums2]) {
                nums1[point_to_insert]=nums2[point_to_end_nums2];
                point_to_end_nums2--;
            } else {
                nums1[point_to_insert]=nums1[point_to_end_nums1];
                point_to_end_nums1--;
            }
            point_to_insert--;
        }
        while (point_to_end_nums2>=0) {
                nums1[point_to_end_nums2]=nums2[point_to_end_nums2];
                point_to_end_nums2--;
            }

    }
};
