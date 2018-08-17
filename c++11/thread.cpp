// thread example
// compile command: g++ --std=c++11 -pthread thread.cpp
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <chrono>

using namespace std;

void foo() {
    int timer = 10;
    while (timer) {
        timer--;
        cout << "foo timer = " << timer << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void bar(int x) {
    int timer = 10;
    while (timer) {
        timer--;
        cout << "bar timer = " << timer << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    thread first(foo);     // spawn new thread that calls foo()
    thread second(bar, 0);  // spawn new thread that calls bar(0)

    cout << "main, foo and bar now execute concurrently...\n";

    int timer = 10;
    while (timer) {
        timer--;
        cout << "main timer = " << timer << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    cout << "foo and bar completed.\n";

    return 0;
}
