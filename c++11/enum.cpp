enum Alert { green, yellow, orange, red }; // traditional enum

enum class Color { red, blue };   // scoped and strongly typed enum
                                  // no export of enumerator names into enclosing scope
                                  // no implicit conversion to int
enum class TrafficLight { red, yellow, green };

int main()
{
    Alert a = 7;              // error (as ever in C++)
    Color c = 7;              // error: no int->Color conversion

    int a2 = red;             // ok: Alert->int conversion
    int a3 = Alert::red;      // error in C++98; ok in C++11
    int a4 = blue;            // error: blue not in scope
    int a5 = Color::blue;     // error: not Color->int conversion

    Color a6 = Color::blue;   // ok

    return 0;
}
