/*

Classes and Objects

Sample Input

3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

Sample Output

1

*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
private:
    vector<int> scores;

public:
    Student() : scores(5) {};
    void input()
    {
        cin>>scores[0]>>scores[1]>>scores[2]>>scores[3]>>scores[4];
    };
    int calculateTotalScore() 
    {
        int ret = 0;
        for (int i = 0; i<scores.size(); i++) {
            ret+=scores[i];
        }
        return ret;
    };
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}