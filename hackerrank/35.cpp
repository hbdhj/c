/*
Copyright 2017 <Deng Haijun>

Breadth First Search: Shortest Reach

*/

#include "./common.h"

const int64 DIST_MAX = -1;

vector<int64> dist;

struct Comp {
    int operator() (const int &v1, const int &v2) {
        return dist[v1] > dist[v2];
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        unordered_map<int, unordered_set<int>> g;

        int n, m; cin >> n >> m;
        int mm = m;
        while (mm--) {
            int x, y;
            cin >> x >> y;
            g[x - 1].insert(y - 1);
            g[y - 1].insert(x - 1);
        }

        // get the source node
        int s;
        cin >> s;
        s--;

        // init dist vector
        dist.assign(n, DIST_MAX);
        dist[s] = 0;

        // inx
        priority_queue<int, vector<int>, Comp> hp;
        hp.push(s);
        while (!hp.empty()) {
            int i = hp.top();
            hp.pop();

            // for each children
            for (auto &c : g[i]) {
                if (dist[c] == DIST_MAX || (dist[i] + 1) < dist[c]) {
                    dist[c] = dist[i] + 1;
                    hp.push(c);
                }
            }
        }

        // output
        for (int i = 0; i < n; i++) {
            if (i != s) {
                cout << (dist[i] == -1 ? -1 : dist[i] * 6) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
