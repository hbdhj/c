/*

Virtual Functions

Sample Input

4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87

Sample Output

Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    virtual void getdata(){};
    virtual void putdata(){};
};

class Professor:public Person {
private:
    int publications;
    int cur_id;
public:
    static int id;
    void getdata(){
        cin>>name>>age>>publications;
        id++;
        cur_id = id;
    };
    void putdata(){
        cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
    };
};

int Professor::id = 0;

class Student:public Person {
private:
    vector<int> marks;
    int cur_id;
public:
    static int id;
    Student() : marks(6) {};
    void getdata(){
        cin>>name>>age;
        id++;
        cur_id = id;
        for(int i=0; i<marks.size(); i++) {
            cin>>marks[i];
        }
    };
    void putdata(){
        cout<<name<<" "<<age<<" "<<sum()<<" "<<cur_id<<endl;
    };
    int sum(){
        int s = 0;
        for(int i=0; i<marks.size(); i++) {
            s+=marks[i];
        }
        return s;
    };
};

int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

