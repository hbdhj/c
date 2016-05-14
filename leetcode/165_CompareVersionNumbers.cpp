class Solution {
public:
    vector<int> parseVersion(string str) {
        vector<int> ret;
        int sum = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '.'){
                ret.push_back(sum);
                sum = 0;
            } else {
                sum = sum * 10 + str[i] - '0';
            }
        }
        ret.push_back(sum);
        return ret;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = parseVersion(version1);
        vector<int> v2 = parseVersion(version2);
        int count1 = v1.size();
        int count2 = v2.size();
        int num1,num2;
        for(int i = 0,j = 0; i < count1 || j < count2; i++,j++){
            num1 = i < count1 ? v1[i] : 0;
            num2 = j < count2 ? v2[j] : 0;
            if(num1 > num2){
                return 1;
            } else if(num1 < num2){
                return -1;
            }
        }
        return 0;
    }
};
