/*

Class

Sample Input

15
john
carmack
10

Sample Output

15
carmack, john
10

15,john,carmack,10

*/

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
private:
    int age;
    string first_name;
    string last_name;
    int standard;

public:
    int get_age()
    {
        return age;
    };
    void set_age(int ag)
    {
        age = ag;
    };
    string get_first_name()
    {
        return first_name;
    };
    void set_first_name(string str)
    {
        first_name = str;
    };
    string get_last_name()
    {
        return last_name;
    };
    void set_last_name(string str)
    {
        last_name = str;
    };
    int get_standard()
    {
        return standard;
    };
    void set_standard(int i)
    {
        standard = i;
    };
    string to_string()
    {
        stringstream ss;
        ss<<age<<","<<first_name<<","<<last_name<<","<<standard;
        return ss.str();
    };
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}