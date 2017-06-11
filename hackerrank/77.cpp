/*
Copyright 2017 <Deng Haijun>

Dashboard > Data Structures > Disjoint Set > Components in a graph 

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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int a, b;
    vector<int> parents(n*2+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (parents[a] == 0)
            parents[a] = a;
        if (parents[b] == 0)
            parents[b] = a;

        // Disjoin set idea, keep updating the representative element of each set.
        if (parents[a] != 0 || parents[b] != 0) {
            int low = min(parents[a], parents[b]);
            int high = max(parents[a], parents[b]);
            for (int j = 0; j < 2*n + 1; j++) {
                if (parents[j] == high)
                    parents[j] = low;
            }
        }
    }

    vector<int> counts(n*2+1, 0);
    for (int j = 0; j < 2*n + 1; j++) {
        counts[parents[j]]++;
    }

    int min_count = 2*n+1;
    int max_count = 0;

    for (int j = 0; j < 2*n + 1; j++) {
        if (counts[j]) {
            min_count = min(min_count, counts[j]);
            max_count = max(max_count, counts[j]);
        }
    }

    cout << min_count << " " << max_count << endl;
    return 0;
}
