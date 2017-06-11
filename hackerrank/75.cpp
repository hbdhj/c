/*
Copyright 2017 <Deng Haijun>

Dashboard > Tutorials > Cracking the Coding Interview > Sorting: Comparator 

Sample Input

5
amy 100
david 100
heraldo 50
aakansha 75
aleksa 150

Sample Output

aleksa 150
amy 100
david 100
aakansha 75
heraldo 50

*/

#include "./common.h"

struct Player {
    string name;
    int score;
};

bool playerComarator(Player a, Player b) {
    if (a.score == b.score) {
        return a.name <= b.name;
    } else {
        return a.score >= b.score;
    }
}

vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), playerComarator);
    return players;
}

int main() {
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }

    vector<Player > answer = comparator(players);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
