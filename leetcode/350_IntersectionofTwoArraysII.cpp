class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inter;
        if(nums1.empty()||nums2.empty())
            return inter;
        int i = 0, j = 0;
        int l1 = nums1.size(), l2 = nums2.size();
        map<int,int>m1;
        map<int,int>m2;
        for(; i < l1; i++)
        {  
            m1[nums1[i]]++;
        }
        for(; j < l2; ++j)
        {  
            m2[nums2[j]]++;
        }
        map<int, int>::iterator it2 = m2.begin();
        while(it2!=m2.end())  
        {
             map<int, int>::iterator it1 = m1.find(it2->first);
             if(it1!=m1.end())  
             {  
                 int tmp = (it1->second)> (it2->second)? (it2->second):(it1->second);  
                 for(int k = 0; k < tmp ; k++)
                 {  
                     inter.push_back(it1->first);
                 }
             }  
             ++it2;
        }
        return inter;
    }
};