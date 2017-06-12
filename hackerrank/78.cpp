/*
Copyright 2017 <Deng Haijun>

All Competitions > Week of Code 33 > Twin Arrays 

Sample Input

5
1 6 
2 7
3 8
4 9
2 6

Sample Output

2 4

Sample Input

10
1 17
5 13
7 12
5 17
5 12
2 17
1 18
8 13
2 15
5 20

Sample Output

11 11

*/

int twinArrays(vector <int> ar1, vector <int> ar2){
    // Complete this function
    int m1 = 100001;
    int m2 = 100001;
    int n1 = 100001;
    int n2 = 100001;
    int i1, i2;
    int j1, j2;
    for (int i = 0; i<ar1.size(); i++) {
        if (ar1[i]<m2) {
            m2 = ar1[i];
            i2 = i;
        }
        if (m2<m1) {
            int tmp = m1;
            m1 = m2;
            m2 = m1;
            tmp = i1;
            i1 = i2;
            i2 = i1;
        }
    }
    for (int i = 0; i<ar2.size(); i++) {
        if (ar2[i]<n2) {
            n2 = ar2[i];
            j2 = i;
        }
        if (n2<n1) {
            int tmp = n1;
            n1 = n2;
            n2 = n1;
            tmp = j1;
            j1 = j2;
            j2 = j1;
        }
    }
    if (i1!=j1)
        return m1+n1;
    else
        return min(m2+n1, n2+m1);
}

int main() {
    int n;
    cin >> n;
    vector<int> ar1(n);
    for(int ar1_i = 0; ar1_i < n; ar1_i++){
       cin >> ar1[ar1_i];
    }
    vector<int> ar2(n);
    for(int ar2_i = 0; ar2_i < n; ar2_i++){
       cin >> ar2[ar2_i];
    }
    int result = twinArrays(ar1, ar2);
    cout << result << endl;
    return 0;
}
